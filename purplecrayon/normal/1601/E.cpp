#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T qry(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

ll t[4 * N];
int lzy[4 * N], mx[4 * N];

void push(int v, int tl, int tr, int x) {
    if (x == -1) return;
    t[v] = (long long) (tr - tl + 1) * x;
    mx[v] = x;
    if (tl != tr)
        lzy[2*v] = x, lzy[2*v+1] = x;
}
void app(int v, int tl, int tr) {
    push(v, tl, tr, lzy[v]), lzy[v] = -1;
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    app(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        push(v, tl, tr, x);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = t[2*v] + t[2*v+1];
    mx[v] = max(mx[2*v], mx[2*v+1]);
}
ll qry(int v, int tl, int tr, int l, int r) {
    app(v, tl, tr);
    if (r < tl || l > tr) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return qry(2*v, tl, tm, l, r) + qry(2*v+1, tm+1, tr, l, r);
}
int last_greater(int v, int tl, int tr, int x) {
    app(v, tl, tr);
    if (mx[v] <= x) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    app(2*v, tl, tm), app(2*v+1, tm+1, tr);
    if (mx[2*v+1] > x) return last_greater(2*v+1, tm+1, tr, x);
    return last_greater(2*v, tl, tm, x);
}
void smin(int l, int r, int x) {
    // r = m-1
    int use = last_greater(1, 0, r, x);
    if (use >= l) upd(1, 0, r, l, use, x);
}

void solve() {
    int n, q, k; cin >> n >> q >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<ar<int, 2>> qs(q);
    vector<vector<ar<int, 2>>> ql(n);
    for (int i = 0; i < q; i++) { 
        int l, r; cin >> l >> r, --l, --r;
        qs[i] = {l, r};
        ql[l].push_back({r, i});
    }
    vector<ll> ans(q);

    RMQ rmq(a);
    vector<vector<int>> me(k);
    for (int i = 0; i < n; i++) me[i % k].push_back(i);
    for (int j = 0; j < k; j++) {
        int m = sz(me[j]);

        upd(1, 0, m-1, 0, m-1, MOD);
        vector<int> b(m, MOD);
        for (int i = 0; i < m - 1; i++) {
            b[i] = rmq.qry(me[j][i], me[j][i + 1] - 1);
        }
        for (int i = m-1; i >= 0; i--) {
            if (i < m-1) {
                smin(i+1, m-1, b[i]);
            }
            upd(1, 0, m-1, i, i, a[me[j][i]]);
            for (auto [r, qt] : ql[me[j][i]]) {
                int R = upper_bound(me[j].begin(), me[j].end(), r) - me[j].begin() - 1;
                ans[qt] = qry(1, 0, m-1, i, R);
            }
        }
    }
    for (auto& x : ans) cout << x << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}