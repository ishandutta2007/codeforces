#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dv=998244353;
map<long long,long long> ls;

int main()
{
	long long i,mx=-1e18,c=-1,z=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ls[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		mx=max(mx,ls[a[i]]);
		c+=mx==i;
	}
	for(i=0;i<c;i++)
	{
		z=z*2%dv;
	}
	printf("%lld\n",z);
}