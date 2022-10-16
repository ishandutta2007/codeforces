#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m;
bitset<1069> a[1069];

int main()
{
	long long t,rr,i,j,ii,mn[2];
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=inf;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='R';
				if(a[i][j])
				{
					for(ii=0;ii<2;ii++)
					{
						mn[ii]=min(mn[ii],i);
						swap(i,j);
					}
				}
			}
		}
		if(a[mn[0]][mn[1]])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}