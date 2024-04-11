#include <bits/stdc++.h>
using namespace std;
const int maxn=305;
const int inf=1000000000;
int n,m;
struct matrix{
	int dis[maxn][maxn];
}origin,power[10],tmp;
inline matrix operator *(const matrix &a,const matrix &b)
{
	static matrix res;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)res.dis[i][j]=-inf;else res.dis[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				if(a.dis[i][k]!=-inf&&b.dis[k][j]!=-inf)
					res.dis[i][j]=max(res.dis[i][j],a.dis[i][k]+b.dis[k][j]);
			}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)origin.dis[i][j]=-inf;
	for(int i=1,x,y,v1,v2;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&v1,&v2);
		origin.dis[x][y]=v1;
		origin.dis[y][x]=v2;
	}
	power[0]=tmp=origin;
	int maxlog;
	for(int i=1;(1<<i)<=n;i++)
	{
		power[i]=power[i-1]*power[i-1];
		maxlog=i;
	}
	int ans=1;
	for(int i=maxlog;i>=0;i--)
	{
		origin=tmp*power[i];
		bool ok=false;
		for(int i=1;i<=n&&!ok;i++)ok|=(origin.dis[i][i]>0);
		if(!ok)
		{
			tmp=origin;
			ans+=1<<i;
		}
	}
	tmp=tmp*power[0];
	ans++;
	for(int i=1;i<=n;i++)
		if(tmp.dis[i][i]>0)
		{
			printf("%d\n",ans);
			return 0;
		}
	puts("0");
	return 0;
}
/*
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 -1
3 4 0 -3
*/