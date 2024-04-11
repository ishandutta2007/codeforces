#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,zs=0;
pair<long long,long long> sq[400069];

void dfs(long long x,long long dh,long long w)
{
	if(dh)
	{
		long long i;
		
		for(i=0;i<w&&zs<n-1;i++)
		{
			zs++;
			sq[zs]={x,zs+1};
			dfs(zs+1,dh-1,d-1);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	if(n-1<m||(d==1&&m>1))
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		zs++;
		sq[zs]={i,i+1};
	}
	for(i=1;i<=m+1;i++)
	{
		dfs(i,min(i-1,m+1-i),d-1-(i>1&&i<=m));
	}
	if(zs<n-1)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}