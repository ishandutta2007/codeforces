#include <bits/stdc++.h>

using namespace std;

long long n,nn,ctd[2],sbt[100069],inf=1e18;
vector<long long> al[100069];
bitset<100069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l,mx=-inf;
	
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
		ctd[nn]=x;
		nn++;
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		nn=0;
		bd(1);
		if(nn==1)
		{
			printf("%lld %lld\n%lld %lld\n",k,l,k,l);
		}
		else
		{
			k=al[ctd[0]][0];
			k=al[ctd[0]][k==ctd[1]];
			printf("%lld %lld\n%lld %lld\n",ctd[0],k,ctd[1],k);
		}
	}
}