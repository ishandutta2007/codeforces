#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
vi g[N];
int deg[N],c[N];
void dfs(int u,int f){
	for(auto v:g[u]){
		if(v==f)continue;
		c[v]=c[u]^1;
		dfs(v,u);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
		deg[u]++,deg[v]++;
	}
	int p=0;
	rep(i,1,n+1)if(deg[i]>1)p=i;
	dfs(p,0);
	int sum=0,ans=0;
	rep(i,1,n+1)if(c[i])++ans;
	c[p]=1;
	dfs(p,0);
	rep(i,1,n+1)if(c[i])++sum;
	ans=min(ans,sum);
	cout<<ans-1;
}