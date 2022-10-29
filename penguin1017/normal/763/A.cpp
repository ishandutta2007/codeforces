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
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
vi g[N];
int color[N];
int rt1=1,rt2=1,flag;
void dfs(int u,int fa){
	if(flag)return;
	for(auto v:g[u]){
		if(v==fa)continue;
		if(color[v]!=color[u]){
			flag=1;
			rt1=u,rt2=v;
			return;
		}
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	} 
}
void dfs2(int u,int fa){
	for(auto v:g[u]){
		if(v==fa)continue;
		if(color[v]!=color[u])flag=1;
		dfs2(v,u);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i,1,n+1)scanf("%d",&color[i]);
	if(n==1){
		printf("YES\n1");
		return 0;
	}
	dfs(1,-1);
	flag=0;
	for(auto u:g[rt1])dfs2(u,rt1);
	if(!flag){
		printf("YES\n%d",rt1);
		return 0;
	}
	flag=0;
	for(auto u:g[rt2])dfs2(u,rt2);
	if(!flag){
		printf("YES\n%d",rt2);
		return 0;
	}
	printf("NO\n");
}