#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[200069];
vector<pair<long long,long long>> al[200069];
pair<long long,long long> as[200069];
bitset<200069> vtd,spc;

void dfs(long long x,long long ls)
{
	long long i,j,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	for(j=0,i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			if(spc[x])
			{
				sq[p]=1;
			}
			else
			{
				for(j++;j==ls;j++);
				sq[p]=j;
			}
			dfs(l,sq[p]);
		}
	}
}

int main()
{
	long long i,k,l,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		as[i].sc=i;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		as[k].fr++;
		as[l].fr++;
	}
	sort(as+1,as+n+1);
	as[0].fr=1;
	z=as[n-d].fr;
	for(i=n-d+1;i<=n;i++)
	{
		k=as[i].sc;
		spc[k]=1;
	}
	dfs(1,0);
	printf("%lld\n",z);
	for(i=1;i<=n-1;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n-1]);
	}
}