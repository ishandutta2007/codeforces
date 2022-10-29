#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7;
const ll inf=1<<30;
// head
const int N=1e6+5;
int n;
VI e[N];
ll ans;
int rt=0,rtv=inf;
int sz[N],psz[N];
void dfs0(int u,int f) {
	int mx=0; sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs0(v,u);
		sz[u]+=sz[v];	
		mx=max(mx,sz[v]);
	}
	mx=max(mx,n-sz[u]);
	if (mx<rtv) rtv=mx,rt=u;
}
void dfs(int u,int f,int depth) {
	ans+=depth;
	psz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u,depth+1);
		psz[u]+=psz[v];
	}
}
void solve(int rt) {
	vector<int> w;
	vector<int> cnt(N,0);
	for (auto v:e[rt]) {
		dfs(v,rt,0);
		w.pb(psz[v]);
		cnt[psz[v]]++;
		ans+=psz[v];
	}
	bitset<1000005> bs;
	bs[0]=1;
	rep(i,1,n+1) if (cnt[i]) {
		int x=cnt[i];
		rep(j,0,20) if (x-(1<<j)>=0) {
			bs|=(bs<<(i*(1<<j)));
			x-=(1<<j);	
		}
		if (x) bs|=bs<<(i*x);
	}
	for (int i=n/2;;i--) if (bs[i]) {
		ans+=(ll)i*(n-1-i);
		break;	
	}
	printf("%lld\n",ans+n);
}

int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		int p;
		scanf("%d",&p);
		e[p].pb(i);e[i].pb(p);
	}
	dfs0(1,0);
	solve(rt);
	return 0;
}