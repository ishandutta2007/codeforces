#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,dsu[200069],fq[200069][2];
pair<pair<long long,long long>,bool> a[200069];
pair<long long,long long> sk[200069];
bitset<200069> lz;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		fd(dsu[x]);
		lz[x]=lz[x]^lz[dsu[x]];
		dsu[x]=dsu[dsu[x]];
	}
	return dsu[x];
}

int main()
{
	long long i,k,l,e,mx=0,p,tg,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		e=0;
		if(k<l)
		{
			swap(k,l);
			e=1;
		}
		a[i]={{k,l},e};
		mx=max(mx,l);
		dsu[i]=i;
	}
	sort(a+1,a+n+1,greater<pair<pair<long long,long long>,bool>>());
	if(a[n].fr.fr<=mx)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		k=a[i].fr.sc;
		l=0;
		for(;k<=a[sk[nn].fr].fr.sc;nn--)
		{
			if(k<=sk[nn].sc)
			{
				printf("-1\n");
				return 0;
			}
			p=sk[nn].fr;
			tg=fd(p);
			dsu[tg]=fd(i);
			lz[tg]=!lz[i]^lz[p];
			if(!l)
			{
				l=p;
			}
		}
		if(!l)
		{
			nn++;
			sk[nn]={i,0};
		}
		else
		{
			nn++;
			sk[nn]={l,k};
		}
	}
	for(i=1;i<=n;i++)
	{
		e=a[i].sc;
		fq[fd(i)][lz[i]^e]++;
	}
	for(i=1;i<=n;i++)
	{
		z+=min(fq[i][0],fq[i][1]);
	}
	printf("%lld\n",z);
}