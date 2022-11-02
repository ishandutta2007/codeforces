#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define inf 10000000000000LL
using namespace std;
int n,mdis;
LL dis[504][504];
vector<pair<int,int> > edge[504];
short dp[504][504][504];
int col[504],sum,res[504][504],siz[504],vis[504];
void init(int x){
	queue<int> que;
	memset(vis,0,sizeof(vis));
	dis[x][x]=0;
	vis[x]=1;
	que.push(x);
	while (!que.empty()){
		int now=que.front();
		que.pop();
		for (int i=0;i<edge[now].size();i++)
		if (!vis[edge[now][i].fi]){
			que.push(edge[now][i].fi);
			vis[edge[now][i].fi]=1;
			dis[x][edge[now][i].fi]=dis[x][now]+edge[now][i].se;
		}
	}
}
void dfs(int x,int y){
	for (int i=0;i<edge[x].size();i++)
	if (edge[x][i].fi!=y) dfs(edge[x][i].fi,x);
	for (int i=1;i<=n;i++)
	if (dis[x][i]<=1LL*mdis){
		siz[x]=0;
		int tmp[2][505],now;
		now=0;
		for (int k=0;k<2;k++)
		for (int h=0;h<=n;h++) tmp[k][h]=1000;
		tmp[0][0]=0;
		for (int j=0;j<edge[x].size();j++)
		if (edge[x][j].fi!=y){
			for (int k=siz[x];k>=0;k--)
			for (int h=siz[edge[x][j].fi];h>=0;h--){
				tmp[now^1][k+h]=min(tmp[now^1][k+h],tmp[now][k]+dp[edge[x][j].fi][i][h]);
				tmp[now^1][k+h]=min(tmp[now^1][k+h],tmp[now][k]+res[edge[x][j].fi][h]);
			}
			for (int k=0;k<=n;k++) tmp[now][k]=1000;
			now^=1;
			siz[x]+=siz[edge[x][j].fi];
		}
		for (int j=0;j<=sum;j++) dp[x][i][j]=tmp[now][j],res[x][j+1]=min(res[x][j+1],dp[x][i][j]+1-col[i]);
	}
	siz[x]+=1;
}
int main(){
	scanf("%d%d",&n,&mdis);
	for (int i=1;i<=n;i++) scanf("%d",&col[i]),sum+=col[i];
	for (int i=1;i<n;i++){
		int o,p,t;
		scanf("%d%d%d",&o,&p,&t);
		edge[o].push_back(make_pair(p,t));
		edge[p].push_back(make_pair(o,t));
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n;j++)
	for (int k=0;k<=n;k++) dp[i][j][k]=1000;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n;j++) res[i][j]=1000;
	for (int i=1;i<=n;i++) init(i);
	dfs(1,0);
	printf("%d\n",(res[1][sum]>sum)?-1:res[1][sum]);
}