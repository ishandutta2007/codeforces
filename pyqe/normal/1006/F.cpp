#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[69][69],z=0;
map<long long,long long> fq[69];

void rk(long long y,long long x,long long xr)
{
	if(y>n||x>m)
	{
		return;
	}
	if(y+x<n+1)
	{
		rk(y+1,x,xr^a[y+1][x]);
		rk(y,x+1,xr^a[y][x+1]);
	}
	else
	{
		fq[y][xr]++;
	}
}

void rk2(long long y,long long x,long long xr)
{
	if(!y||!x)
	{
		return;
	}
	if(y+x>n+1)
	{
		rk2(y-1,x,xr^a[y][x]);
		rk2(y,x-1,xr^a[y][x]);
	}
	else
	{
		z+=fq[y][xr^d];
	}
}

int main()
{
	long long i,j;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	rk(1,1,a[1][1]);
	rk2(n,m,0);
	printf("%lld\n",z);
}