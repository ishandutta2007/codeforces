#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,nn=0,nr[2069][2069],sl[2069],wg[2069],sk[2069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return mp(x/y,x%y*y2)>=mp(x2/y2,x2%y2*y);
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(wg[x]-wg[y2],sl[y2]-sl[x],wg[x]-wg[y],sl[y]-sl[x]);
}

long long f(long long x,long long w)
{
	return sl[x]*w+wg[x];
}

int main()
{
	long long i,j,ii,u,lh,rh,md,zz,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	n++;
	m++;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			nr[i][j]=inf*(ch=='0');
		}
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=2+(n-3)*ii;i&&i<=n;i+=u)
		{
			for(j=1;j<=m;j++)
			{
				nr[i][j]=min(nr[i][j],nr[i-u][j]+1);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		nn=0;
		for(j=1;j<=m;j++)
		{
			if(nr[i][j]!=inf)
			{
				sl[j]=j*-2;
				wg[j]=j*j+nr[i][j]*nr[i][j];
				for(;nn>=2&&chk(j,sk[nn],sk[nn-1]);nn--);
				nn++;
				sk[nn]=j;
			}
		}
		for(j=1;j<=m;j++)
		{
			for(zz=1,lh=2,rh=nn;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(f(sk[md],j)<=f(sk[md-1],j))
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			z+=f(sk[zz],j)+j*j;
		}
	}
	printf("%lld\n",z);
}