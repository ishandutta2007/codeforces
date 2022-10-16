#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[200069];
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,k,l,k2,l2,sm,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			k2=max(m-l,0ll);
			l2=min(k,m);
			a[i]={k2,l2};
			sm+=l-(m-l2)-(k-l2);
		}
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			w=min(max(sm,0ll)/2,l-k);
			sm-=w*2;
			sq[i]=l-w;
		}
		printf("%lld\n",abs(sm));
		for(i=1;i<=n;i++)
		{
			printf("%lld %lld\n",sq[i],m-sq[i]);
		}
	}
}