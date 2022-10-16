#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d[2];
pair<long long,long long> pr[49][49][49][89];
bitset<100069> sq;

int main()
{
	long long t,rr,i,j,r,k,p,e,e2,e3;
	pair<long long,long long> z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,d,d+1);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<d[0];j++)
			{
				for(r=0;r<d[1];r++)
				{
					for(p=-n;p<=n;p++)
					{
						pr[i][j][r][n+p].fr=-1;
					}
				}
			}
		}
		pr[0][0][0][n].fr=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			for(j=0;j<d[0];j++)
			{
				for(r=0;r<d[1];r++)
				{
					for(p=-n;p<=n;p++)
					{
						if(pr[i-1][j][r][n+p].fr+1)
						{
							if(p<n)
							{
								pr[i][(j*10+k)%d[0]][r][n+p+1]={0,j};
							}
							if(p>-n)
							{
								pr[i][j][(r*10+k)%d[1]][n+p-1]={1,r};
							}
						}
					}
				}
			}
		}
		z={inf,inf};
		for(i=-n+1;i<=n-1;i++)
		{
			if(pr[n][0][0][n+i].fr+1)
			{
				z=min(z,{abs(i),i});
			}
		}
		e=z.sc;
		if(e==inf)
		{
			printf("-1\n");
			continue;
		}
		e2=0;
		e3=0;
		for(i=n;i;i--)
		{
			sq[i]=pr[i][e2][e3][n+e].fr;
			if(!sq[i])
			{
				e2=pr[i][e2][e3][n+e].sc;
			}
			else
			{
				e3=pr[i][e2][e3][n+e].sc;
			}
			e-=!sq[i]*2-1;
		}
		for(i=1;i<=n;i++)
		{
			printf("%c","RB"[sq[i]]);
		}
		printf("\n");
	}
}