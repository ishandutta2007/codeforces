#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> vl[200069],al[200069];
bitset<200069> vtd,dh;
bool bad;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=!dh[x];
			dfs(l);
		}
		bad|=dh[l]==dh[x];
	}
}

int main()
{
	long long t,rr,i,k,l,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
			al[i].clear();
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			vl[k].push_back(i);
			vl[l].push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			sz=vl[i].size();
			if(sz>2)
			{
				break;
			}
			if(sz==2)
			{
				k=vl[i][0];
				l=vl[i][1];
				al[k].push_back(l);
				al[l].push_back(k);
			}
		}
		if(i<=n)
		{
			printf("NO\n");
			continue;
		}
		bad=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				dfs(i);
			}
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}