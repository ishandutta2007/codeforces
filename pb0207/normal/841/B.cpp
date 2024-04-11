#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e6+1e3+7; 

int n,a[N],s,flag;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)
			flag=true;
		s+=a[i];
	}
	if(s&1)
	{
		cout<<"First";
	}
	else
	{
		if(flag)
			cout<<"First";
		else
			cout<<"Second";
	}
}