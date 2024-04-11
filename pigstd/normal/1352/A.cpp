#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	cin>>t;
	while(t--)
	{
		int a,sum=0;
		cin>>a;
		int a1=a%10;
		int a2=a%100/10;
		int a3=a%1000/100;
		int a4=a%10000/1000;
		int a5=a%100000/10000;
		int a6=a%1000000/100000;
		if (a1!=0)
			sum++;
		if (a2!=0)
			sum++;
		if (a3!=0)
			sum++;
		if (a4!=0)
			sum++;
		if (a5!=0)
			sum++;
		if (a6!=0)
			sum++;
		cout<<sum<<endl;
		if (a1!=0)
			cout<<a1<<' ';
		if (a2!=0)
			cout<<a2<<"0 ";
		if (a3!=0)
			cout<<a3<<"00 ";
		if (a4!=0)
			cout<<a4<<"000 ";
		if (a5!=0)
			cout<<a5<<"0000 ";
		if (a6!=0)
			cout<<a6<<"000000 ";
		cout<<endl;
	}
	return 0;
}