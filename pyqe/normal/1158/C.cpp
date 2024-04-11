#include <bits/stdc++.h>

using namespace std;

long long n,pr[500069],mn[500069],sq[500069],zs;
vector<long long> al[500069];
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(mn[x]<=mn[l])
		{
			r0=1;
			return;
		}
		dfs(l);
		if(r0)
		{
			return;
		}
		mn[x]=mn[l];
	}
	zs++;
	sq[x]=zs;
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n+1;i++)
		{
			al[i].clear();
			mn[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pr+i);
			if(pr[i]==-1)
			{
				pr[i]=i+1;
			}
		}
		for(i=n;i;i--)
		{
			al[pr[i]].push_back(i);
		}
		r0=0;
		zs=0;
		dfs(n+1);
		if(r0)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}