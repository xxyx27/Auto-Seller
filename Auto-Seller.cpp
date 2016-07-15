#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <windows.h>
using namespace std;
void cls(){system("cls");};//ϵͳ����

struct Drink{
	Drink(float pr, string n);
	string name;//����
	float price;//�۸�
	int account;//����
};
//����veeding��
class Vending{
public:
	Vending();

	inline void showStorage() const {//��Ʒ���Ƽ�����
		cout << "���֣�" << m_cola->account << endl << "�̲裺" << m_milkT->account << endl;
		cout << "���裺" << m_T->account << endl;
	}
	inline void showSoldNum() const{//ͳ����������
		cout << m_cola->name << endl << "��������" << m_soldCola << endl;
		cout << "���۶" << m_soldCola*(m_cola->price) << endl;
		cout << m_milkT->name << endl << "��������" << m_soldMilkTea << endl;
		cout << "���۶" << m_soldMilkTea*(m_milkT->price) << endl;
		cout << m_T->name << endl << "��������" << m_soldTea << endl;
		cout << "���۶" << m_soldTea*(m_T->price) << endl;
	}

	void addStore();
	void sellItem();
	void popMenu();

private:
	Drink *m_cola, *m_milkT, *m_T;
	int m_soldCola, m_soldMilkTea, m_soldTea;
};

Drink::Drink(float pr, string n)
:name(n), price(pr), account(0){}

Vending::Vending()
:m_soldCola(0), m_soldMilkTea(0), m_soldTea(0)
{
	m_cola = new Drink(float(2.8), "����");
	m_milkT = new Drink(float(3.0), "�̲�");
	m_T = new Drink(float(3.5), "����");
}
//��治�㣬ʵ�ֶ���Ʒ���
void Vending::addStore(){
	cout << "��ѡ��Ҫ�ϼܵ���Ʒ��\n1.����\n2.�̲�\n3.����\n";
	int n, count;
	cin >> n;

	if(n > 3){
		cout << "ѡ�����" << endl;
		return;
	}

	cout << "������Ҫ�ϼܵ�������";
	cin >> count;

	if(n == 1)
		m_cola->account += count;
	else if(n == 2)
		m_milkT->account += count;
	else if(n == 3)
		m_T->account += count;
	else{
		cout << "����ʧ��" << endl;
		return;
	}

	cout << "�������" << endl;
    Sleep(1000);//�ӳ�����
	cls();
}
//��ʾ���ʣ��
void Vending::sellItem(){
	cout << "1." << m_cola->name << "��" << endl;
	cout << "�۸�" << m_cola->price << ends << "��棺" << m_cola->account << (m_cola->account == 0 ? "�����꣩\n" : "\n");
	cout << "2." << m_milkT->name << "��" << endl;
	cout << "�۸�" << m_milkT->price << ends << "��棺" << m_milkT->account << (m_milkT->account == 0 ? "�����꣩\n" : "\n");
	cout << "3." << m_T->name << "��" << endl;
	cout << "�۸�" << m_T->price << ends << "��棺" << m_T->account << (m_T->account == 0 ? "�����꣩\n" : "\n");
	cout << "��ѡ��";
	int n = 0, num = 0;
	cin >> n;

	float price = 0;
	int acc = 0;
	if(n == 1){
		price = m_cola->price;
		acc = m_cola->account;
	}
	else if(n == 2){
		price = m_milkT->price;
		acc = m_milkT->account;
	}
	else if(n == 3){
		price = m_T->price;
		acc = m_T->account;
	}

	do
	{
		if(num > 0)
			cout << "��治��" << endl;

		cout << "������������";
		cin >> num;
	}while(num > acc);

	price *= num;

	float pay = 0;
	do
	{
		if(pay > 0)
			cout << "֧������" << endl;//ʵ���տ����

		cout << "��֧����";
		cin >> pay;
	}while (pay < price);


	if(pay - price > 0)
		cout << "���㣺" << pay-price << endl;
cout << "�������" << endl;
	Sleep(1000*3);
	cls();
	if(n == 1){
		m_soldCola += num;
		m_cola->account -= num;
	}
	else if(n == 2){
		m_soldMilkTea += num;
		m_milkT->account -= num;
	}
	else if(n == 3){
		m_soldTea += num;
		m_T->account -= num;
	}
}
//������
void Vending::popMenu(){
	const string menu1 = "========�Զ�������========\n1.������Ա����\n2.���۽���\n3.�˳�\n";
	const string menu2 = "========�Զ�������========\n1.��ʾ���\n2.��Ʒ�ϼ�\n3.���۲�ѯ\n";

	int n;
	while(true){
		cout << menu1 << "��ѡ��";//�˶Թ���Ա
		cin >> n;

		if(n == 1){
            cls();
			cout << "���������룺";
			int password;
			cin >> password;
			cls();
			if(password != 123){
				cout << "�������" << endl;
				continue;
			}
        loop:cout << menu2 << "��ѡ��";
			cin >> n;
			cls();

            switch(n){
			case 1:{
				showStorage();
				break;
				   }
			case 2:{
				addStore();
				break;
				   }
			case  3:{
				showSoldNum();
				break;
					}
			default:{
				cout << "ѡ�����,����ѡ��" << endl;
				//return;
				goto loop;
					}
			}
		}
		else if(n == 2)
        {cls();
			sellItem();}
		else if(n == 3)
		    {cls();
			exit(0);}
	}
}

int main(){
    //freopen("in.txt","r",stdin);
	Vending *vend = new Vending;
	vend->popMenu();
	return 0;
}
