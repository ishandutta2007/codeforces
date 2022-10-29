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
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
int dp[N][20],a[N],sz[N];
ll ans; 
vi g[N];
void dfs(int u,int f){
	sz[u]=1;
	rep(i,0,20)dp[u][i]=a[u]>>i&1;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		rep(i,0,20){
			if(a[u]>>i&1){
				dp[u][i]+=sz[v]-dp[v][i];
			}
			else{
				dp[u][i]+=dp[v][i];
			}
		}
	} 
}
void dfs2(int u,int f){
	rep(i,0,20)ans+=1ll*dp[u][i]*(1<<i);
//	cout<<ans<<"ans\n";
	for(auto v:g[u]){
		if(v==f)continue;
		int sum=sz[u]-sz[v];
		rep(i,0,20){
			if(a[u]>>i&1){
				dp[u][i]-=sz[v]-dp[v][i];
			}
			else{
				dp[u][i]-=dp[v][i];
			}
		}
		rep(i,0,20){
			if(a[v]>>i&1){
				dp[v][i]+=sum-dp[u][i];
			}
			else{
				dp[v][i]+=dp[u][i];
			}
		}
		sz[v]+=sum;
		dfs2(v,u);
		sz[v]-=sum;
		rep(i,0,20){
			if(a[v]>>i&1){
				dp[v][i]-=sum-dp[u][i];
			}
			else{
				dp[v][i]-=dp[u][i];
			}
		}
		rep(i,0,20){
			if(a[u]>>i&1){
				dp[u][i]+=sz[v]-dp[v][i];
			}
			else{
				dp[u][i]+=dp[v][i];
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]),ans+=a[i];
//	cout<<ans<<"ans\n";
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u); 
	}
	dfs(1,0);
	dfs2(1,0);
	printf("%lld",ans>>1);
}