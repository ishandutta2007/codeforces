#include <bits/stdc++.h>

using namespace std;

long long n,d,sbt[100069],a[100069];
vector<long long> al[100069];
bitset<100069> vtd;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,sm=-sbt[x];
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				return;
			}
			sbt[x]+=sbt[l];
			sm+=a[l];
		}
	}
	if(sm>a[x]||abs(sm%2)!=abs(a[x]%2)||sbt[x]<a[x])
	{
		r0=1;
		return;
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",sbt+i);
			al[i].clear();
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		r0=0;
		dfs(1);
		if(!r0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}