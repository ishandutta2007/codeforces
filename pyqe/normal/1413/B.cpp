#include <bits/stdc++.h>

using namespace std;

long long n,m,pst[250069][2],sq[569][569];

int main()
{
	long long t,rr,i,j,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					scanf("%lld",&k);
					pst[k][!ii]=j;
				}
			}
			swap(n,m);
		}
		for(i=1;i<=n*m;i++)
		{
			sq[pst[i][0]][pst[i][1]]=i;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%lld%c",sq[i][j]," \n"[j==m]);
			}
		}
	}
}