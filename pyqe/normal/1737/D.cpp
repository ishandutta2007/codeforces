#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,am[569][569],am2[569][569];

int main()
{
	long long t,rr,i,j,r,k,l,w,w2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				am[i][j]=inf*(i!=j);
				am2[i][j]=inf*(i!=j);
			}
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			am[k][l]=1;
			am[l][k]=1;
			am2[k][l]=min(am2[k][l],w);
			am2[l][k]=min(am2[l][k],w);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(r=1;r<=n;r++)
				{
					am[j][r]=min(am[j][r],am[j][i]+am[i][r]);
				}
			}
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				w=am2[i][j];
				if(w!=inf)
				{
					w2=min(am[1][i]+am[j][n],am[1][j]+am[i][n]);
					for(r=1;r<=n;r++)
					{
						w2=min(w2,min(am[i][r],am[j][r])+1+am[1][r]+am[r][n]);
					}
					z=min(z,w*(w2+1));
				}
			}
		}
		printf("%lld\n",z);
	}
}