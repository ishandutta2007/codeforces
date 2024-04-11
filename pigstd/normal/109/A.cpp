#include<bits/stdc++.h>
using namespace std;

int x,y,a;
bool flag;
//4*x+7*y=a
//x+y 
//y 

int main()
{
	cin>>a;
	for (int i=a/7;i>-1;i--)
	{
		int k=a-i*7;
		if (k%4==0)
			{x=k/4,y=i,flag=1;break;}
	}
	if (!flag)
		{cout<<-1;return 0;}
	for (int i=1;i<=x;i++)
		cout<<4;
	for (int i=1;i<=y;i++)
		cout<<7;
	return 0;
}