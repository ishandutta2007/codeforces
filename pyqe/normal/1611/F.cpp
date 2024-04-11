#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn=0,ps[200069];
pair<long long,long long> sk[200069];

int main()
{
	long long t,rr,i,p;
	pair<long long,long long> z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",ps+i);
			ps[i]+=ps[i-1];
		}
		nn=0;
		sk[0].sc=n+1;
		z.fr=0;
		for(i=n;i>=0;i--)
		{
			for(;nn&&sk[nn].fr>ps[i];nn--);
			nn++;
			sk[nn]={ps[i],i};
			p=lower_bound(sk+1,sk+nn+1,mp(ps[i]-d,0ll))-sk-1;
			z=max(z,{sk[p].sc-(i+1),i+1});
		}
		if(z.fr)
		{
			printf("%lld %lld\n",z.sc,z.sc+z.fr-1);
		}
		else
		{
			printf("-1\n");
		}
	}
}