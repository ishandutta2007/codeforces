#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x.begin(),x.end())
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head

const int N=3e5+5;
int n,mn,cmn;
VI e[N];
int dep[N],res[N];
void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	res[u]=inf;
	int cnt=0;
	for (auto v:e[u]) if (v!=f) {
		cnt++;
		dfs(v,u);
		res[u]=min(res[u],res[v]);
	}
	if (cnt<2) {
		if (dep[u]<mn) mn=dep[u],cmn=cnt;
		else if (dep[u]==mn) cmn=min(cmn,cnt);
	}
}
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) e[i].clear();
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	mn=inf,cmn=inf;
	dfs(1,0);
	printf("%d\n",n-(mn-1)*2-1-(cmn==1));
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
	return 0;
}