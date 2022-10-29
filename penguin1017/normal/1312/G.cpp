#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=1e6+9;
const ll mod=998244353;
vector<pair<char,int>> g[N];
int q[N],ans[N],sz[N],vis[N],cnt,n,k;
void dfs(int u,int f){
	if(u==f){
		sz[u]=1;
		ans[u]=++cnt;
		return;
	}
	for(auto w:g[u]){
		dfs(w.se,u);
		if(u!=w.se)sz[u]+=sz[w.se];
	}
}
void solve(int u,int pre,int x){
	if(vis[u])ans[u]=min(x,pre+1);
	else ans[u]=pre+1;
	if(x>ans[u]+1)x=ans[u]+1;
	int num=0;
	for(auto w:g[u]){
		if(!sz[w.se])continue;
		if(w.se==u){
			num++;
			continue;
		}
		else{
			solve(w.se,ans[u],x+num);
			num+=sz[w.se];
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1){
		int p;
		char s[2];
		scanf("%d%s",&p,s);
		g[p].pb({s[0],i});
	}
	scanf("%d",&k);
	rep(i,0,k)scanf("%d",&q[i]),g[q[i]].pb({0,q[i]}),vis[q[i]]=1;
	rep(i,0,n+1)sort(all(g[i]));
	dfs(0,-1);
	solve(0,-1,1);
	rep(i,0,k)printf("%d ",ans[q[i]]);
}