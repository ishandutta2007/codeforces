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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<x<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
vi g[N];
int dp[2][N],maxn[2][N],maxn2[2][N],sz[N],ans;
void dfs(int u,int f){
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		sz[u]++;
		if(maxn[0][u]<dp[0][v]){
			maxn2[0][u]=maxn[0][u];
			maxn[0][u]=dp[0][v];
		}
		else if(maxn2[0][u]<dp[0][v])maxn2[0][u]=dp[0][v];
		int mx=max(dp[0][v],dp[1][v]);
		if(maxn[1][u]<mx){
			maxn2[1][u]=maxn[1][u];
			maxn[1][u]=mx;
		}
		else if(maxn2[1][u])maxn2[1][u]=mx; 
	}
	dp[1][u]=maxn[0][u]+1;
	dp[0][u]=maxn[1][u]+sz[u]-1;
	dp[0][u]=max(dp[0][u],0);
//	cout<<u<<' '<<dp[1][u]<<' '<<dp[0][u]<<"dp\n";
}
void dfs2(int u,int f){
//	cout<<u<<' '<<f<<"check\n";
	int sz2=sz[u];
	if(f){
		sz[u]++;
		if(maxn[0][u]<dp[0][f]){
			maxn2[0][u]=maxn[0][u];
			maxn[0][u]=dp[0][f];
		}
		else if(maxn2[0][u]<dp[0][f])maxn2[0][u]=dp[0][f];
		int mx=max(dp[0][f],dp[1][f]);
		if(maxn[1][u]<mx){
			maxn2[1][u]=maxn[1][u];
			maxn[1][u]=mx;
		} 
		else if(maxn2[1][u]<mx)maxn2[1][u]=mx;
		dp[1][u]=maxn[0][u]+1;
		dp[0][u]=maxn[1][u]+sz[u]-1;
		dp[0][u]=max(dp[0][u],0);
	}
	else sz2--;
	ans=max(ans,max(dp[0][u],dp[1][u]));
	//cout<<u<<' '<<dp[0][u]<<' '<<dp[1][u]<<"check\n";
	for(auto v:g[u]){
		if(v==f)continue;
		int temp[2];
		temp[0]=dp[0][u],temp[1]=dp[1][u];
		if(dp[0][u]==max(dp[0][v],dp[1][v])+sz[u]-1){
			dp[0][u]=maxn2[1][u]+sz2-1;
			dp[0][u]=max(dp[0][u],0);
		}
		else{
			dp[0][u]=maxn[1][u]+sz2-1;
			dp[0][u]=max(dp[0][u],0);
		}
		if(dp[1][u]==dp[0][v]+1){
			dp[1][u]=maxn2[0][u]+1;
		}
		//cout<<dp[1][u]<<' '<<dp[0][u]<<"dp\n";
		//cout<<v<<' '<<u<<"??\n";
		dfs2(v,u);
		dp[0][u]=temp[0],dp[1][u]=temp[1];
	}
}
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0);
	printf("%d",ans);
}