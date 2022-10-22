#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int N=15;

int c[N],m;

int main()
{
	for(int i=1;i<=5;i++)
		scanf("%d",&c[i]),m+=c[i];
	if(m/5*5!=m)
		cout<<"-1"<<endl;
	else
	if(m<=0)
		cout<<"-1"<<endl;
	else
	{
		cout<<m/5;
	}
}