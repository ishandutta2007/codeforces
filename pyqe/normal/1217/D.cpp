#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[5069],z,c;
pair<long long,long long> a[5069];
vector<long long> v;
vector<pair<long long,long long>> al[5069];
bitset<5069> vtd,vtd2;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(vtd2[l])
		{
			v.push_back(p);
			c++;
		}
		if(!vtd[l])
		{
			dfs(l);
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,k,l,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
		v.push_back(i);
		c++;
	}
	for(z=0;c>0;z++)
	{
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<c;i++)
		{
			p=v[i];
			k=a[p].fr;
			l=a[p].sc;
			al[k].push_back({l,p});
			sq[p]=z+1;
		}
		v.clear();
		c=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				dfs(i);
			}
		}
	}
	printf("%lld\n",z);
	for(i=0;i<m;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==m-1]);
	}
}