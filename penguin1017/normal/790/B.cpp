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
const int N=2e5+9;
const ll mod=998244353;
int sum[N][5],k;
vi g[N];
ll ans[N],res;
void dfs(int u,int f){
	sum[u][0]=1;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		ans[u]+=sum[v][0]+ans[v];
		rep(i,0,k)sum[u][(i+1)%k]+=sum[v][i];
	}
}
void dfs2(int u,int f){
	res+=ans[u];
	for(auto v:g[u]){
		if(v==f)continue;
		int tot[5];
		rep(i,0,k)tot[(i+1)%k]=sum[u][(i+1)%k]-sum[v][i];
		ans[u]-=ans[v]+sum[v][0];
		rep(i,0,k)sum[v][(i+1)%k]+=tot[i];
		ans[v]+=tot[0]+ans[u];
		dfs2(v,u);
		ans[v]-=tot[0]+ans[u];
		rep(i,0,k)sum[v][(i+1)%k]-=tot[i];
		ans[u]+=ans[v]+sum[v][0];
	}
}
int main(){
	int n;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u); 
	}
	dfs(1,-1);
	dfs2(1,-1);
//	rep(i,1,n+1)cout<<ans[i]<<' ';
	printf("%lld",res>>1);
}