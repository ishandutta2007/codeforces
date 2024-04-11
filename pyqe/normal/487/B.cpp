#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn[2],a[100069],sk[2][100069],fw[100069],fi,sp[17][100069],lg2[100069],inf=1e18;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long bl(long long x)
{
	long long i,sm=0;
	
	for(fi=0,i=16;i+1;i--)
	{
		if((fi|1ll<<i)<=n&&sm+fw[fi|1ll<<i]>x)
		{
			fi|=1ll<<i;
			sm+=fw[fi];
		}
	}
	return fi;
}

long long spqr(long long lh,long long rh)
{
	if(lh>rh)
	{
		return inf;
	}
	long long e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]);
}

int main()
{
	long long i,j,ii,u,k,l,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	a[0]=inf;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(;nn[ii]&&a[sk[ii][nn[ii]]]*u<=a[i]*u;nn[ii]--)
			{
				k=sk[ii][nn[ii]];
				l=sk[ii][nn[ii]-1];
				ud(l+1,abs(a[i]-a[k]));
				ud(k+1,-abs(a[i]-a[k]));
			}
			nn[ii]++;
			sk[ii][nn[ii]]=i;
		}
		sp[0][i]=spqr(bl(m),i-d)+1;
		for(j=1;1ll<<j<=i;j++)
		{
			sp[j][i-(1ll<<j)+1]=min(sp[j-1][i-(1ll<<j)+1],sp[j-1][i-(1ll<<j-1)+1]);
		}
	}
	z=sp[0][n];
	if(z>=inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}