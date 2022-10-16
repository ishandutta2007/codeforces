#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n,ttl=0;
pair<long long,long long> a[200069];

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i,k,w,sm=0,z;
	
	scanf("%lld%lld",&ln,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&w);
		a[i]={k,w};
		ttl+=w;
	}
	if(ttl>ln)
	{
		printf("-1\n");
		return 0;
	}
	else if(ttl<ln)
	{
		printf("1\n");
		return 0;
	}
	sort(a+1,a+n+1);
	a[n+1]={ln+1,0};
	z=tri(ln);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		w=a[i].sc;
		sm+=w;
		z-=sm*(a[i+1].fr-k);
	}
	if(abs(z)%ln==0)
	{
		printf("1\n");
	}
	else
	{
		printf("-1\n");
	}
}