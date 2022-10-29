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
const int N=2e5+9;
const ll mod=998244353;
const ll Inf=1e18;
int t[N],H[N],out[N],in[N];
ll f[N],h[N],a[N];
vi g[N];
bool vis[N];
void dfs(int u, int fa) {
	vis[u] = true;
	for (int i = 0, v; i < g[u].size(); i++) {
		if ((v = g[u][i]) == fa) continue;
		dfs(v, u);
	}
	int s = 0;
	ll cur = 0;
	for (int i = 0, v; i < g[u].size(); i++) {
		if ((v = g[u][i]) == fa) continue;
		cur += h[v], a[++s] = f[v] - h[v];
	}
	sort(a + 1, a + s + 1);
	reverse(a + 1, a + s + 1);
	for (int i = 0; i <= s; i++) {
		cur += a[i];
		if (fa) {
			f[u] = max(f[u], 1ll * min(in[u] + 1 + s - i, out[u] + i) * t[u] + cur);
			h[u] = max(h[u], 1ll * min(in[u] + s - i, out[u] + 1 + i) * t[u] + cur);
		} else {
			f[u] = max(f[u], 1ll * min(in[u] + s - i, out[u] + i) * t[u] + cur);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&t[i]);
	rep(i,1,n+1)scanf("%d",&H[i]);
	ll ans=0;
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		ans+=t[u]+t[v];
		if(H[u]==H[v]){
			g[u].pb(v);
			g[v].pb(u);
		}
		else{
			if(H[u]>H[v])swap(u,v);
			in[u]++;
			out[v]++;
		}
	}
	rep(i,1,n+1){
		if(!vis[i])dfs(i,0),ans-=f[i];
	}
	printf("%lld",ans);
}