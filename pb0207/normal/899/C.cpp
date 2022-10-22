#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n%4==0)
	{
		cout<<0<<endl;
		cout<<n/2<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
	}
	if(n%4==2)
	{
		cout<<1<<endl;
		cout<<n/2<<" ";
		for(int i=1;i<n/2;i+=2)
			cout<<i<<" "<<n-i+1<<" ";
		cout<<n/2;
	}
	if(n%4==1)
	{
		cout<<1<<endl;
		cout<<n/2+1<<" ";
		n-=1;
		for(int i=1;i<n/2;i+=2)
			cout<<i+1<<" "<<n-i+1+1<<" ";
		cout<<1;
	}
	if(n%4==3)
	{
		cout<<0<<endl;
		cout<<n/2+1<<" ";
		n-=3;
		for(int i=1;i<n/2;i+=2)
			cout<<i+3<<" "<<n-i+1+3<<" ";
		cout<<1<<" "<<2;
	}
}