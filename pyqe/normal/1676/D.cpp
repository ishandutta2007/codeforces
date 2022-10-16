#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069],pc[2][2069];

int main()
{
	long long t,rr,i,j,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<=n+m;i++)
			{
				pc[ii][i]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&a[i][j]);
				pc[0][i+j]+=a[i][j];
				pc[1][i+m-j]+=a[i][j];
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				z=max(z,pc[0][i+j]+pc[1][i+m-j]-a[i][j]);
			}
		}
		printf("%lld\n",z);
	}
}