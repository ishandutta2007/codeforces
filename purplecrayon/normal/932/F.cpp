#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
} hull[MAXN];

int n, loc[MAXN];
vector<int> adj[MAXN];
ll a[MAXN], b[MAXN], ans[MAXN];

void merge(int c, int nxt){
    if (sz(hull[loc[c]]) < sz(hull[loc[nxt]])) swap(loc[c], loc[nxt]);
    for (auto l : hull[loc[nxt]]) hull[loc[c]].add(l.k, l.m);
    hull[loc[nxt]].clear();
}
void dfs(int c=0, int p=-1){
    ans[c] = (c&&sz(adj[c])==1)?0:INF;
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs(nxt, c); merge(c, nxt);
    }
    // cout << "C: " << c << "\n"; for (auto l : hull[loc[c]]) cout << l.k << " " << l.m << "\n";
    // cout << "END: " << c << "\n";
    if (sz(hull[loc[c]]))  ans[c] = min(ans[c], -hull[loc[c]].query(a[c]));
    hull[loc[c]].add(-b[c], -ans[c]);
}
void solve(){
    cin >> n;
    iota(loc, loc+n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cin >> b[j];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(); for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}