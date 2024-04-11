#include <bits/stdc++.h>

using namespace std;

long long n,c=0,dg[200069],eu[200069],pst[200069];
vector<long long> cd[200069];

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l;
	
	c++;
	eu[c]=x;
	pst[x]=c;
	dg[x]=1;
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		dg[x]+=dg[l];
	}
}

int main()
{
	long long i,t,rr,k,l;
	
	scanf("%lld%lld",&n,&t);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		cd[k].push_back(i);
	}
	dfs(1);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(l>dg[k])
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",eu[pst[k]+l-1]);
		}
	}
}