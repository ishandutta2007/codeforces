#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m,a[100005],dis[100005],vis[100005],q[100005],head,tail,R,G,visp[505];
bitset<1005> f[10005][2],g[10005][2],tmp,tmp2;
int getans(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	scanf("%d%d",&G,&R);
	int ng=G/2;
	f[1][0][0]=1;
	for(int j=2;j<=m;j++)
	{
		int v=a[j]-a[j-1];
		f[j][0][0]=1;
		for(int i=v;i<=ng;i++)
			f[j][0][i]=f[j][0][i]|f[j][0][i-v]|f[j-1][0][i-v];
	}
	f[m][1][0]=1;
	for(int j=m-1;j>0;j--)
	{
		int v=a[j+1]-a[j];
		f[j][1][0]=1;
		for(int i=v;i<=ng;i++)
			f[j][1][i]=f[j][1][i]|f[j][1][i-v]|f[j+1][1][i-v];
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=ng;k++)
			{
				g[i][j][ng-k]=f[i][j][k];
				//printf("i=%d,j=%d,k=%d,f=%d\n",i,j,k,(int)f[i][j][k]);
			}
	head=0,tail=1;
	q[1]=1;
	vis[1]=1,dis[1]=0;
	while(head<tail)
	{
		head++;
		int u=q[head];
	//	printf("u=%d\n",u);
		/*for(int i=max(u-G,1);i<=min(u+G,m);i++)
			if(!vis[i]&&getans(a[i]-a[u])<=G&&(G-getans(a[i]-a[u]))%2==0)
			{
				dis[i]=dis[u]+1;
				vis[i]=1;
				q[++tail]=i;
			}*/
		memset(visp,0,sizeof(visp));
		tmp=f[u][0];
		for(int i=u+1;i<=m;i++)
		{
			int val=getans(a[i]-a[u]),v2=getans(a[i]-a[i-1]);
			if(val>G) break;
			if(v2>500||!visp[v2])
			{
				if(v2<=500) visp[v2]=1;
				int tnw=(ng+v2)/v2;
				while(tnw>1)
				{
					tmp=tmp|(tmp<<((tnw+1)/2*v2));
					tnw=(tnw+1)/2;
				}
			}
		/*	printf("i=%d,tmp=",i);
			for(int j=0;j<=ng;j++)
				printf("%d",(int)tmp[j]);
			printf("\n");*/
			if(!vis[i]&&val<=G&&(G-val)%2==0)
			{
				int nw=(G-val)/2;
				if((tmp&(g[i][1]>>(ng-nw))).count())
				{
					dis[i]=dis[u]+1;
					vis[i]=1;
					q[++tail]=i;
				}
			}
		}
		memset(visp,0,sizeof(visp));
		tmp=f[u][1];
		for(int i=u-1;i>0;i--)
		{
			int val=getans(a[i]-a[u]),v2=getans(a[i]-a[i+1]);
			if(val>G) break;
			if(v2>500||!visp[v2])
			{
				if(v2<=500) visp[v2]=1;
				int tnw=(ng+v2)/v2;
				while(tnw>1)
				{
					tmp=tmp|(tmp<<((tnw+1)/2*v2));
					tnw=(tnw+1)/2;
				}
			}
			if(!vis[i]&&val<=G&&(G-val)%2==0)
			{
				int nw=(G-val)/2;
				if((tmp&(g[i][0]>>(ng-nw))).count())
				{
					dis[i]=dis[u]+1;
					vis[i]=1;
					q[++tail]=i;
				}
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<m;i++)
	{
		//printf("i=%d,vis=%d,dis=%d,a=%d\n",i,vis[i],dis[i],a[i]);
		if(vis[i]&&getans(a[i]-n)<=G)
		{
			ans=min(ans,dis[i]*(R+G)+getans(a[i]-n));
		}
	}
	if(ans!=1e9) printf("%d",ans);
	else printf("-1");
	return 0;
}