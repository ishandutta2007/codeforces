#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[1069][1069];
vector<long long> vl[1069];
vector<bool> vtd[1069];

int main()
{
	long long t,rr,i,j,r,k,l,p,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
			vtd[i].clear();
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				if(ch=='0')
				{
					vl[j].push_back(i);
					vtd[j].push_back(0);
					c++;
				}
				sq[i][j]=0;
			}
		}
		for(i=1;i<=d-1;i++)
		{
			k=n;
			for(j=i;j<=n;j++)
			{
				sq[k][j]++;
				p=upper_bound(vl[j].begin(),vl[j].end(),k)-vl[j].begin()-1;
				for(;p>=0&&!vtd[j][p];p--)
				{
					l=vl[j][p];
					vtd[j][p]=1;
					for(r=l;r<k;r++)
					{
						sq[r][j]++;
					}
					k=l;
					c--;
				}
			}
			for(j=i;j<k;j++)
			{
				sq[j][n]++;
			}
		}
		if(c)
		{
			printf("NO\n");
			continue;
		}
		for(i=n;i;i--)
		{
			for(j=n;j;j--)
			{
				sq[i-1][j-1]+=max(sq[i][j]-1,0ll);
			}
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%lld",(long long)!!sq[i][j]);
			}
			printf("\n");
		}
	}
}