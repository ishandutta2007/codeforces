#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[100069];
pair<pair<long long,long long>,long long> as[100069];

int main()
{
	long long t,rr,i,k,l,w,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].sc);
		as[i].fr.sc=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr.fr);
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		pst[as[i].fr.sc]=i;
	}
	for(i=1,rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		k=pst[k];
		z=0;
		w=min(l,as[k].sc);
		z+=w*as[k].fr.fr;
		l-=w;
		as[k].sc-=w;
		for(;l&&i<=n;i+=!as[i].sc)
		{
			w=min(l,as[i].sc);
			z+=w*as[i].fr.fr;
			l-=w;
			as[i].sc-=w;
		}
		z*=!l;
		printf("%lld\n",z);
	}
}