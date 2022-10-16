#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[100069],sm[2],dg[100069],sq[100069];
pair<long long,long long> ed[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd,dh,spc,ex;
queue<long long> q;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	sm[dh[x]]+=a[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=!dh[x];
			dfs(l);
			ex[p]=1;
		}
		else if(dh[l]==dh[x])
		{
			spc[p]=1;
		}
	}
}

int main()
{
	long long i,k,l,p,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	dfs(1);
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(spc[i])
		{
			sq[i]=(sm[dh[k]]-sm[!dh[k]])/2;
			a[k]-=sq[i];
			a[l]-=sq[i];
			sm[dh[k]]=sm[!dh[k]];
		}
		dg[k]+=ex[i];
		dg[l]+=ex[i];
	}
	if(sm[0]!=sm[1])
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==1)
		{
			q.push(i);
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			p=al[k][i].sc;
			if(ex[p])
			{
				sq[p]=a[k];
				a[l]-=a[k];
				ex[p]=0;
				dg[l]--;
				if(dg[l]==1)
				{
					q.push(l);
				}
			}
		}
	}
	printf("YES\n");
	for(i=1;i<=m;i++)
	{
		printf("%lld\n",sq[i]);
	}
}