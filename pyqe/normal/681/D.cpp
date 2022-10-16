#include <bits/stdc++.h>

using namespace std;

long long n,m,pr[100069],a[100069],sq[100069],zs=0;
vector<long long> al[100069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	if(a[x]==x)
	{
		zs++;
		sq[zs]=x;
	}
	else if(a[x]!=a[pr[x]])
	{
		printf("-1\n");
		exit(0);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		pr[l]=k;
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		if(!pr[i])
		{
			dfs(i);
		}
	}
	printf("%lld\n",zs);
	for(i=zs;i;i--)
	{
		printf("%lld\n",sq[i]);
	}
}