#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;

int n;
int val[maxn];
char str[maxn];
int head[maxn],nxt[maxn<<1],to[maxn<<1],edge_tot;
void add_edge(int u,int v){nxt[++edge_tot]=head[u];head[u]=edge_tot;to[edge_tot]=v;}
const int S=20;
int root;
int siz[maxn],mxson[maxn];
bool vis[maxn];
void init(){
	memset(vis,0,sizeof(vis));
	mxson[0]=inf;
}
void get_root(int u,int f,int sum){
	mxson[u]=0,siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		get_root(v,u,sum);
		siz[u]+=siz[v];
		mxson[u]=max(mxson[u],siz[v]);
	}
	mxson[u]=max(mxson[u],sum-siz[u]);
	if(mxson[u]<mxson[root])root=u;
}
int cnt[1<<21];
void add(int u,int f,int sta,int op){
	sta^=(1<<val[u]);
	cnt[sta]+=op;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		add(v,u,sta,op);
	}
}
ll ans[maxn];
ll calc(int u,int f,int sta){
	sta^=(1<<val[u]);
	ll res=cnt[sta];
	for(int i=0;i<S;i++)res+=cnt[sta^(1<<i)];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		res+=calc(v,u,sta);
	}
	ans[u]+=res;
	return res;
}
void solve(int u=1,int sum=n){
	root=0;get_root(u,0,sum);
	vis[root]=1;
	add(root,0,0,1);
	ll num=0;
	num+=cnt[0];
	for(int i=0;i<S;i++)num+=cnt[1<<i];
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		add(v,root,1<<val[root],-1);
		num+=calc(v,root,0);
		add(v,root,1<<val[root],1);
	}
	ans[root]+=num/2;
	add(root,0,0,-1);
	int root_sz=siz[root];
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		solve(v,root_sz>siz[v]?siz[v]:sum-root_sz);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)val[i]=str[i]-'a';
	init();
	solve();
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]+1);
	return 0;
}