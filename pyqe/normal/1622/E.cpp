#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,ttl,wg[69],cwg[10069],fq[69],pst[69],ca[10069],z,sq[10069];
bitset<10069> a[69];

void rk(long long x)
{
	if(x<=n)
	{
		long long i,ii,u;
		
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			ttl-=wg[x]*u;
			for(i=1;i<=m;i++)
			{
				cwg[i]+=a[x][i]*u;
			}
			rk(x+1);
			for(i=1;i<=m;i++)
			{
				cwg[i]-=a[x][i]*u;
			}
			ttl+=wg[x]*u;
		}
	}
	else
	{
		long long i,sm=0;
		
		for(i=-n;i<=n;i++)
		{
			fq[n+i]=0;
		}
		for(i=1;i<=m;i++)
		{
			fq[n+cwg[i]]++;
		}
		pst[0]=1;
		for(i=-n+1;i<=n;i++)
		{
			pst[n+i]=pst[n+i-1]+fq[n+i-1];
		}
		for(i=1;i<=m;i++)
		{
			ca[i]=pst[n+cwg[i]];
			pst[n+cwg[i]]++;
			sm+=ca[i]*cwg[i];
		}
		if(ttl+sm>z)
		{
			z=ttl+sm;
			for(i=1;i<=m;i++)
			{
				sq[i]=ca[i];
			}
		}
	}
}

int main()
{
	long long t,rr,i,j;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",wg+i);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
			}
		}
		ttl=0;
		for(i=1;i<=m;i++)
		{
			cwg[i]=0;
		}
		z=-inf;
		rk(1);
		for(i=1;i<=m;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==m]);
		}
	}
}