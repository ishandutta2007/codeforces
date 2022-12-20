#include <iostream>
#include <string>
using namespace std;

int main()
{
	int len,tot;
	cin >> len >> tot;
	if((len==1)&&(tot==0))
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	string a,b;
	a = "1";
	for(int i=1;i<len;i++)
		a += "0";
	b = "";
	for(int i=0;i<len;i++)
		b += "9";
	int tA = 1;
	int tB = 9*len;
	if(tot<tA)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	if(tot>tB)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	for(int i=(len-1);i>=0;i--)
	{
		if(tA==tot)
			break;
		int dif = min(9,tot-tA);
		a[i] += dif;
		tA += dif;
	}
	for(int i=(len-1);i>=0;i--)
	{
		if(tB==tot)
			break;
		int dif = max(-9,tot-tB);
		b[i] += dif;
		tB += dif;
	}
	cout << a << " " << b << endl;
}