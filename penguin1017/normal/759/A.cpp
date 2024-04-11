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
int vis[N],cnt;
void dfs(int u){
	cnt++;
	vis[u]=1;
	for(auto v:g[u]){
		if(vis[v])continue;
		dfs(v);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(v,1,n+1){
		int u;
		scanf("%d",&u);
		g[u].pb(v);
	}
	int ans=0,a;
	rep(i,1,n+1){
		scanf("%d",&a);
		ans^=a;
	}
	ans^=1;
	a=0;
	int tot=0;
	rep(i,1,n+1){
		if(vis[i])continue;
		cnt=0;
		dfs(i);
		a++;
	}
	if(a>1)ans+=a; 
	cout<<ans;
}