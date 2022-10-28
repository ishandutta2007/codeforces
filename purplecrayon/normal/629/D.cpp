#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
 
struct Tree {
	typedef long long T;
	static constexpr T unit = LLONG_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
        s[pos + n] = max(s[pos + n], val);
		for (pos += n; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


int n;
ll a[MAXN];
map<ll, int> mp;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll r, h; cin >> r >> h;
        a[i] = r*r*h;
    }
    for (int i = 0; i < n; i++) mp[a[i]]++;
    int cc = 0;
    for (auto& c : mp) c.second = cc++;

    Tree tree(cc + 1, 0);
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        ll dp = tree.query(mp[a[i]] + 1, cc) + a[i];
        ans = max(ans, dp);
        tree.update(mp[a[i]], dp);
    }
    const long double PI = 3.141592635897932384626;
    cout << fixed << setprecision(10) << ((long double) ans) * PI << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}