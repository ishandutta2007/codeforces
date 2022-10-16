#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[200069];
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]={k,i};
		}
		sort(a+1,a+n+1,greater<pair<long long,long long>>());
		z=0;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			z+=k*((i+1)/2)*2;
			sq[l]=(i+1)/2*(i%2*2-1);
		}
		printf("%lld\n",z);
		for(i=0;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}