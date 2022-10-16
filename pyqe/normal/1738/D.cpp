#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],dg[100069],sq[100069],zs;
vector<long long> al[100069];

bool cdg(long long x,long long y)
{
	return dg[x]<dg[y];
}

int main()
{
	long long t,rr,i,l,sz,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		d=0;
		for(i=0;i<=n+1;i++)
		{
			al[i].clear();
			dg[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(a[i]>i)
			{
				d=i;
			}
			al[a[i]].push_back(i);
			dg[a[i]]++;
		}
		zs=0;
		p=0;
		if(!dg[0])
		{
			p=n+1;
		}
		for(;1;)
		{
			sort(al[p].begin(),al[p].end(),cdg);
			sz=al[p].size();
			for(i=0;i<sz;i++)
			{
				l=al[p][i];
				zs++;
				sq[zs]=l;
			}
			if(!dg[l])
			{
				break;
			}
			p=l;
		}
		printf("%lld\n",d);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}