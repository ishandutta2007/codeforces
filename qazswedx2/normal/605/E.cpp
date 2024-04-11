#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,vis[1005];
double g[1005][1005],dis[1005],p[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%lf",&g[i][j]);
			g[i][j]/=100;
		}
	for(int i=1;i<n;i++)
	{
		if(g[i][n]) dis[i]=1.0/g[i][n];
		else dis[i]=1e18;
		p[i]=g[i][n];
	}
	vis[n]=1;
	int tt=n-2;
	while(tt-->0)
	{
		int id=0;
		double mn=1e18+1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&mn>dis[i])
			{
				mn=dis[i];
				id=i;
			}
		vis[id]=1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				double q=g[i][id]*(1-p[i]);
			//	printf("i=%d,p=%f,q=%f,dis=%f,%f\n",i,p[i],q,dis[i],dis[id]);
				if(p[i]+q) dis[i]=((dis[i]-1/(p[i]?p[i]:1e-18))*p[i]+dis[id]*q+1)/(p[i]+q);
				else dis[i]=1e18;
				p[i]+=q;
			}
		/*printf("mn=%f,id=%d\n",mn,id);
		for(int i=1;i<=n;i++)
			printf("%.2f ",dis[i]);
		printf("\n");*/
	}
	printf("%.10f",dis[1]);
	return 0;
}