#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,dsu[100069],wg[100069];
pair<long long,pair<long long,long long>> ed[2000069];

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
	long long i,j,k,l,w,mx=0;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		dsu[i]=i;
		for(j=i*2;j<=n;j+=i)
		{
			nn++;
			ed[nn]={j/i,{i,j}};
		}
	}
	sort(ed+1,ed+nn+1,greater<pair<long long,pair<long long,long long>>>());
	for(i=1;i<=nn;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		w=ed[i].fr;
		if(fd(k)!=fd(l))
		{
			wg[fd(k)]+=wg[fd(l)];
			dsu[fd(l)]=fd(k);
		}
		wg[fd(k)]+=w;
		mx=max(mx,wg[fd(k)]);
	}
	printf("%lld\n",mx*4);
}