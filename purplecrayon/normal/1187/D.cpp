#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

struct Tree {
	typedef int T;
	static constexpr T unit = MOD;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void upd(int pos, T val) {
        s[pos + n] = f(s[pos + n], val);
		for (pos += n; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T qry(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;
    vector<int> b(n); for (auto& x : b) cin >> x, --x;

    vector<vector<int>> locA(n), locB(n);
    for (int i = 0; i < n; i++) locA[a[i]].push_back(i);
    for (int i = 0; i < n; i++) locB[b[i]].push_back(i);

    vector<int> where(n);
    for (int i = 0; i < n; i++) {
        if (sz(locA[i]) != sz(locB[i])) {
            cout << "NO\n";
            return;
        }
        for (int j = 0; j < sz(locA[i]); j++) {
            where[locA[i][j]] = locB[i][j];
        }
    }
    Tree tree(n);
    for (int i = 0; i < n; i++) {
        // j < i, where[j] > where[i], a[j] < a[i]
        if (tree.qry(where[i], n-1) < a[i]) {
            cout << "NO\n";
            return;
        }
        tree.upd(where[i], a[i]);
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}