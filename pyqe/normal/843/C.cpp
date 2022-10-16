#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ctd,cr,cr2,rt,sbt[200069],zs=0;
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,pair<long long,long long>> sq[400069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,mx=0;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l];
			mx=max(mx,sbt[l]);
		}
	}
	mx=max(mx,n-sbt[x]);
	if(mx*2<=n)
	{
		ctd=x;
	}
}

void trv(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			if(sbt[x]*2>=n)
			{
				cr=x;
				cr2=l;
				rt=l;
			}
			else if(x!=rt)
			{
				zs++;
				sq[zs]={cr,{cr2,l}};
				cr2=l;
				zs++;
				sq[zs]={l,{x,rt}};
			}
			trv(l);
			if(sbt[x]*2>=n&&sbt[l]*2<n)
			{
				zs++;
				sq[zs]={cr,{cr2,rt}};
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	k=ctd;
	vtd.reset();
	bd(k);
	vtd.reset();
	trv(k);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr,sq[i].sc.fr,sq[i].sc.sc);
	}
}