#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
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
const int N=2e5+5;


void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	vector<VI> e(n);
	vector<int> deg(n),a(n);
	rep(i,0,n) scanf("%d",&a[i]);
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		e[u].pb(v),e[v].pb(u);
		deg[u]++,deg[v]++;
	}

	if (~m&1) puts("0");
	else {
		int mn=1<<30;
		rep(i,0,n) if (deg[i]&1) mn=min(mn,a[i]);
		rep(i,0,n) if (~deg[i]&1) {
			for (auto v:e[i]) {
				if (~deg[v]&1) {
					mn=min(mn,a[i]+a[v]);
				}
			}
		}
		printf("%d\n",mn);
	}


}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}