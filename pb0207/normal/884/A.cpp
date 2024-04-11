#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n,t;

int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		t-=86400-x;
		if(t<=0)
		{
			cout<<i;
			return 0;
		}
	}
}