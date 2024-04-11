#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[3333],pool[233333];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int pa[3333][3333],siz[3333][3333];//pa[root][node]
long long dp[3333][3333];
void dfs(int u,int r)
{
	siz[r][u]=1;
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(pa[r][u]!=tmp->v)
		{
			pa[r][tmp->v]=u;
			dfs(tmp->v,r);
			siz[r][u]+=siz[r][tmp->v];
		}
	}
}
long long gao(int u,int v)
{
//	cerr<<"gao "<<u<<' '<<v<<endl;
	if(u==v)return 0;
	if(dp[u][v])return dp[u][v];
	long long ret=max(gao(pa[u][v],u)+siz[v][u]*siz[u][v],gao(pa[v][u],v)+siz[v][u]*siz[u][v]);
	return dp[u][v]=dp[v][u]=ret;
}
int n,k,x,y;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++)cin>>x>>y,addedge(x,y);
	for(int i=1;i<=n;i++)dfs(i,i);
/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cerr<<i<<' '<<j<<' '<<pa[i][j]<<' '<<siz[i][j]<<endl;
		}
	}
	system("pause");
*/
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans=max(ans,gao(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}