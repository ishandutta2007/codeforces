#include<iostream>
#include<cstdio>
using namespace std;

long long a,b;

long long ans=1;

int main()
{
	cin>>a>>b;
	long long k=min(a,b);
	for(int i=1;i<=k;i++)
		ans*=i;
	cout<<ans;
}