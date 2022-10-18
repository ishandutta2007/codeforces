#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,dsu[200069],inf=1e18;
pair<long long,long long> ed[200069],as[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,k,l,w,pz,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		mn=inf;
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			ed[i]={k,l};
			as[i]={w,i};
			mn=min(mn,abs(w-d));
		}
		sort(as+1,as+m+1);
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
		}
		z=0;
		for(i=1;i<=m;i++)
		{
			w=as[i].fr;
			pz=as[i].sc;
			k=ed[pz].fr;
			l=ed[pz].sc;
			z+=max(w-d,0ll)*(fd(k)!=fd(l));
			dsu[fd(l)]=fd(k);
		}
		z+=mn*!z;
		printf("%lld\n",z);
	}
}