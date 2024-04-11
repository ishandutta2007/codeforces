#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sp[2][17][100069],lg2[100069];

void spbd()
{
	long long i,j,ii,u,k;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=n;i++)
		{
			sp[ii][0][i]=a[i];
		}
	}
	for(i=1;1ll<<i<=n+1;i++)
	{
		for(j=0;j<=n-(1ll<<i)+1;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				sp[ii][i][j]=min(sp[ii][i-1][j]*u,sp[ii][i-1][j+(1ll<<i-1)]*u)*u;
			}
		}
	}
	for(i=1;i<=n+1;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

long long spqr(long long xx,long long lh,long long rh)
{
	long long u=!xx*2-1,e=lg2[rh-lh+1];
	
	return min(sp[xx][e][lh]*u,sp[xx][e][rh-(1ll<<e)+1]*u)*u;
}

int main()
{
	long long t,rr,i,ii,k,l,z;
	
	scanf("%lld%lld",&n,&t);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]=-a[i]-k;
		}
	}
	for(i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	spbd();
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(a[k-1]!=a[l]||spqr(1,k-1,l)>a[k-1])
		{
			z=-1;
		}
		else
		{
			z=a[k-1]-spqr(0,k-1,l);
		}
		printf("%lld\n",z);
	}
}