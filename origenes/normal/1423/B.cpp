#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1

typedef long long LL;

const int N=110000;
const int M=1100000;
const LL mod=1e9+7;
const int MAXN=110000;
const int inf=1e9;
vector<int> g[MAXN];
int nx,tx[MAXN],ty[MAXN],dx[MAXN],dy[MAXN],dis;
bool flag[MAXN];
bool bfs(){
	queue<int> q;
	dis=inf;
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	for (int i=1;i<=nx;i++) if (tx[i]==-1){
		q.push(i);
		dx[i]=0;
	}
	while (!q.empty()){
		int u=q.front();
		q.pop();
		if (dx[u]>dis) break;
		for (int i=0;i<g[u].size();i++) {
			int v=g[u][i];
			if (dy[v]==-1){
				dy[v]=dx[u]+1;
				if (ty[v]==-1) dis=dy[v];
				else {
					dx[ty[v]]=dy[v]+1;
					q.push(ty[v]);
				}
			} 
		}
	}
	return dis!=inf;
}
bool dfs(int u){
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (!flag[v] && dy[v]==dx[u]+1){
			flag[v]=1;
			if (ty[v]!=-1 && dy[v]==dis) continue;
			if (ty[v]==-1|| dfs(ty[v])){
				ty[v]=u;
				tx[u]=v;
				return 1;
			}
		}
	}
	return 0;
}
int HC(){
	int ans=0;
	memset(tx,-1,sizeof(tx));
	memset(ty,-1,sizeof(ty));
	while (bfs()){
		memset(flag,0,sizeof(flag));
		for (int i=1;i<=nx;i++)if (tx[i]==-1 && dfs(i)) ans++;
	}
	return ans;
} 
int n,m;
struct edge
{
	int x,y,w;
	friend bool operator < (edge a,edge b)
	{
		return a.w<b.w;
	}
}e[M];
int ans=-1;
int check(int x)
{
	for (int i=1;i<=n;i++)
		g[i].clear();
	for (int i=1;i<=x;i++)
	{
		int x=e[i].x,y=e[i].y,w=e[i].w;
		g[x].pb(y);
	}
	int res=HC();
	return res==n;
}
int main()
{
	scanf("%d %d",&n,&m);
	nx=n;
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		e[i].x=x,e[i].y=y,e[i].w=w;
	}
	sort(e+1,e+1+m);
	int l=1,r=m;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1,ans=e[mid].w;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}