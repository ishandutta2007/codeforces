#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<569> a[569];
bitset<1069> am[1069],vtd;
bool r0;

void mxf(long long x)
{
	long long i;
	
	vtd[x]=1;
	if(x==n+1)
	{
		r0=1;
		return;
	}
	for(i=1;i<=n+m;i++)
	{
		if(am[x][i]&&!vtd[i])
		{
			mxf(i);
			if(r0)
			{
				am[x][i]=0;
				am[i][x]=1;
				return;
			}
		}
	}
}

int main()
{
	long long i,j,c=0,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='B';
		}
	}
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			a[i][j]=a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
			z+=a[i][j];
		}
	}
	for(i=2;i<=n;i++)
	{
		am[1][i]=1;
		for(j=2;j<=m;j++)
		{
			am[n+j][n+1]=1;
			if(a[i][1]&&a[1][j]&&a[i][j])
			{
				am[i][n+j]=1;
			}
		}
	}
	for(r0=1;r0;)
	{
		r0=0;
		vtd.reset();
		mxf(1);
		c+=r0;
	}
	z-=c+(a[1][1]*2-1)*(c%2);
	printf("%lld\n",z);
}