#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ps[100069],inf=1e18;
bitset<100069> bs;

int main()
{
	long long i,sm=0,z=-inf;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
	}
	cin>>s;
	for(i=1;i<=n;i++)
	{
		bs[i]=s[i-1]-'0';
	}
	for(i=n;i;i--)
	{
		if(bs[i])
		{
			z=max(z,sm+ps[i-1]);
			sm+=a[i];
		}
	}
	z=max(z,sm);
	printf("%lld\n",z);
}