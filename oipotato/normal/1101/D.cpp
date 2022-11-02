#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=200010;
vector<int>g[N],id[N];
int ans,a[N],n,tot,fa[N],pri[N][20],cnt[N];
bool vis[N],notp[N];
void dfs(int p)
{
	rep(i,cnt[a[p]])id[pri[a[p]][i]].pb(p);
	for(auto i:g[p])if(i!=fa[p])fa[i]=p,dfs(i);
}
int work(int p)
{
	vis[p]=0;
	int mx=1;
	for(auto i:g[p])
	if(vis[i])
	{
		int x=work(i);
		ans=max(ans,mx+x);
		mx=max(mx,x+1);
	}
	ans=max(ans,mx);
	return mx;
}
int main()
{
	notp[1]=1;
	rep(i,200000)if(!notp[i])for(int j=i;j<=200000;j+=i)pri[j][++cnt[j]]=i,notp[j]=1;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);
	}
	dfs(1);
	rep(i,n)g[i].clear();
	rep(i,200000)
	if(id[i].size())
	{
		//printf("%d:",i);for(auto j:id[i])printf("%d ",j);puts("");
		for(auto j:id[i])
		{
			vis[j]=1;
			if(vis[fa[j]])g[fa[j]].pb(j);
		}
		for(auto j:id[i])
		{
			if(vis[j])work(j);
			g[j].clear();
		}
	}
	printf("%d\n",ans);
	return 0;
}