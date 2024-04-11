#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e5+1e3+7;

int n,a,b,c;

int bit[11][2];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<10;i++)
		bit[i][1]=1;
	for(int i=1;i<=n;i++)
	{
		char op[3];
		int x;
		scanf("%s%d",op,&x);
		if(op[0]=='|')
			for(int j=0;j<10;j++)
				bit[j][0]|=((x>>j)&1),bit[j][1]|=((x>>j)&1);
		if(op[0]=='^')
			for(int j=0;j<10;j++)
				bit[j][0]^=((x>>j)&1),bit[j][1]^=((x>>j)&1);
		if(op[0]=='&')
			for(int j=0;j<10;j++)
				bit[j][0]&=((x>>j)&1),bit[j][1]&=((x>>j)&1);
	}
	c=1023;
	for(int i=0;i<10;i++)
	{
		if(bit[i][0]==1&&bit[i][1]==0)
			a+=(1<<i);
		if(bit[i][0]==1&&bit[i][1]==1)
			b+=(1<<i);
		if(bit[i][0]==0&&bit[i][1]==0)
			c-=(1<<i);
	}
	cout<<3<<endl;
	cout<<'|'<<" "<<b<<endl;
	cout<<'&'<<" "<<c<<endl;
	cout<<'^'<<" "<<a<<endl;
}