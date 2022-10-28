#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n;
int a[MAXN], b[MAXN];
set<int> loc[MAXN];

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
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


void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        loc[a[i]].insert(i);
    }

    Tree seg(n);
    for (int i = 0; i < n; i++) seg.update(i, 1);

    ll ans = 0;
    int cur = 0;
    sort(b, b+n);

    for (int i = 0; i < n; i++) {
        int c = b[i];

        auto it = loc[c].lower_bound(cur);
        if (it == loc[c].end()) {
            it = loc[c].begin();
        }

        int nxt = *it; loc[c].erase(it);

        int jump = 0;
        if (nxt < cur) jump += seg.query(cur, n-1)+seg.query(0, nxt);
        else jump += seg.query(cur, nxt);

        ans += jump;

        seg.update(nxt, 0);
        cur = nxt;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}