#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)
	{
		int t=a;
		a=b;
		b=t;
	}
	int d=b-a;
	if(d==0)
	{
		cout<<0;
		return 0;
	}
	if(a>d)
	{
		a%=d;
		if(a)d-=a;
		else d=0;
		cout<<d;
	}
	else 
	{
		if(d%a==0)cout<<0;
		else
		{
			int i,q,j;
			q=(int)sqrt(d+0.5);
			for(i=2;i<=d;i=j+1)
			{
				j=d/i;
				j=d/j;
				if(d%j==0&&j>=a)break;
			}
			cout<<j-a;
		}
	}
}