#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,p,sm=0,ls=0,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(z=0;1;z++)
	{
		p=lower_bound(a+ls+1,a+n+1,sm)-a;
		if(p>n)
		{
			break;
		}
		sm+=a[p];
		ls=p;
	}
	printf("%lld\n",z);
}