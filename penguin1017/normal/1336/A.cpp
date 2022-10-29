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
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
vi g[N];
int dep[N],sz[N],sum[N];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int u,int f){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);sz[u]+=sz[v];
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	rep(i,1,n+1){
		sum[i]=dep[i]-sz[i]+1;
		//cout<<sum[i]<<' '<<dep[i]<<' '<<sz[i]<<"check\n"; 
	}
	sort(sum+1,sum+1+n,cmp);
	ll ans=0;
	rep(i,1,k+1)ans+=sum[i];
	cout<<ans;
}