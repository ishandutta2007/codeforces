#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

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
	ll qry(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
} hull;

int n;
ll a[MAXN], ps1[MAXN], ps2[MAXN], ans = 0;

void solve(){
    cin >> n; ps1[0] = ps2[0] = 0;
    for (int i = 0; i < n; i++) cin >> a[i], ps1[i+1] = a[i]+ps1[i], ps2[i+1] = a[i]*(i+1)+ps2[i];
    //ans for range l, r
    //ps2[r+1]-ps2[l]-l*(ps1[r+1]-ps1[l])
    //ps2[r+1]-ps2[l]-l*ps1[r+1]+l*ps1[l]
    for (int i = n-1; i >= 0; i--){
        hull.add(-ps1[i+1], ps2[i+1]);
        ans = max(ans, i*ps1[i]-ps2[i]+hull.qry(i));
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}