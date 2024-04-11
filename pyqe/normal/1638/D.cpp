#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[1069][1069],zs=0;
bitset<1069> vtd[1069];
queue<pair<long long,long long>> q;
pair<pair<long long,long long>,long long> sq[1000069];

inline void chk(long long y,long long x)
{
	if(y>0&&x>0&&y<n&&x<m&&!vtd[y][x])
	{
		long long ii,jj,k=a[y][x];
		
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				if(a[y+ii][x+jj]!=-1)
				{
					if(k==-1||a[y+ii][x+jj]==k)
					{
						k=a[y+ii][x+jj];
					}
					else
					{
						return;
					}
				}
			}
		}
		if(k!=-1)
		{
			zs++;
			sq[zs]={{y,x},k};
			q.push({y,x});
			vtd[y][x]=1;
		}
	}
}

int main()
{
	long long i,j,ii,jj,y,x;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			chk(i,j);
		}
	}
	for(;!q.empty();)
	{
		y=q.front().fr;
		x=q.front().sc;
		q.pop();
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				a[y+ii][x+jj]=-1;
			}
		}
		for(ii=-1;ii<=1;ii++)
		{
			for(jj=-1;jj<=1;jj++)
			{
				chk(y+ii,x+jj);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]!=-1)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%lld\n",zs);
	for(i=zs;i;i--)
	{
		printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
	}
}