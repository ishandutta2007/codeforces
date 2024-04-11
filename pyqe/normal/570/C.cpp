#include <bits/stdc++.h>

using namespace std;

long long n,z=0;
bitset<300069> a;

void ud(long long x,long long w)
{
	long long u;
	
	for(u=-1;u<=1;u+=2)
	{
		z+=a[x+u]*(w-a[x]);
	}
	a[x]=w;
}

int main()
{
	long long t,rr,i,k;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		ud(i,ch=='.');
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld %c",&k,&ch);
		ud(k,ch=='.');
		printf("%lld\n",z);
	}
}