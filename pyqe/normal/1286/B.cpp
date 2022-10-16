#include <bits/stdc++.h>

using namespace std;

long long n,a[2069],sbt[2069],pst[2069],sq[2069],c=0;
vector<long long> cd[2069];

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l;
	
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=cd[x][i];
		dfs(l);
		sbt[x]+=sbt[l];
	}
	c++;
	if(a[x]>=sbt[x])
	{
		printf("NO\n");
		exit(0);
	}
	for(i=c-1;i>c-sbt[x]+a[x];i--)
	{
		swap(pst[i],pst[i+1]);
	}
	pst[c-sbt[x]+a[x]+1]=x;
}

int main()
{
	long long i,k,rt;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,a+i);
		if(!k)
		{
			rt=i;
		}
		else
		{
			cd[k].push_back(i);
		}
	}
	dfs(rt);
	for(i=1;i<=n;i++)
	{
		sq[pst[i]]=i;
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}