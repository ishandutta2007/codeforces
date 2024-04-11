#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[369][369];

int main()
{
	long long t,rr,i,j,k,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		bad=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&k);
				sq[i][j]=(i>1)+(j>1)+(i<n)+(j<m);
				if(k>sq[i][j])
				{
					bad=1;
				}
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					printf("%lld%c",sq[i][j]," \n"[j==m]);
				}
			}
		}
	}
}