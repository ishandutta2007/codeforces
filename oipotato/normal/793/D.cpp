#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=233333333;
int link[85][85],f[85][85][85][85],n,m,k,x,y,z,ans;
bool vis[85][85][85][85];
int DP(int l,int r,int p,int k)
{
	if(vis[l][r][p][k])return f[l][r][p][k];
	if(p<1||p>n)return INF;
	if(k==1)return 0;
	vis[l][r][p][k]=1;
	int &tans=f[l][r][p][k];
	tans=INF;
	if(p==l-1)
	for(int i=1;i<=l-1;i++)
	tans=min(tans,min(DP(i,r,r+1,k-1)+link[r+1][p],DP(i,r,i-1,k-1)+link[i-1][p]));
	if(p==r+1)
	for(int i=r+1;i<=n;i++)
	tans=min(tans,min(DP(l,i,l-1,k-1)+link[l-1][p],DP(l,i,i+1,k-1)+link[i+1][p]));
	//printf("f[%d][%d][%d][%d]=%d\n",l,r,p,k,f[l][r][p][k]);
	return tans;
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	link[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		link[x][y]=min(link[x][y],z);
	}
	ans=INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)ans=min(ans,DP(j,i-1,i,k));
		for(int j=i+1;j<=n;j++)ans=min(ans,DP(i+1,j,i,k));
	}
	if(k==1)ans=0;
	if(ans==INF)printf("-1");
	else printf("%d",ans);
	return 0;
}