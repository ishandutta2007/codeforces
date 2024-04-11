#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e4+10, MOD = 1e9+7;

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
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T qry(int a, int b) {
        if (a > b) return -1;
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

void solve() {
    int n, q; cin >> n >> q;
    vector<ar<int, 3>> qs(q);
    vector<vector<int>> ev(n + 1);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x, --l, --r;
            qs[i] = {l, r, x};
            if (x == 0) ev[l].push_back(i), ev[r+1].push_back(i);
        } else {
            int j; cin >> j, --j;
            qs[i] = {-1, -1, j};
        }
    }

    vector<int> zero(n);
    set<int> s;
    set<int> use;
    for (int i = 0; i < n; i++) {
        for (int x : ev[i]) {
            if (s.count(x)) s.erase(x);
            else s.insert(x);
        }
        if (sz(s)) zero[i] = *s.begin();
        else {
            zero[i] = MOD; 
            use.insert(i);
        }
    }
    RMQ qry(zero);
    vector<int> one(n, MOD);
    for (int i = 0; i < q; i++) {
        if (qs[i][0] != -1) {
            auto [l, r, x] = qs[i];
            if (x == 1) {
                auto it = use.lower_bound(l);
                if (it != use.end()) {
                    int c = *it;
                    one[c] = min(one[c], max({i, qry.qry(l, c - 1), qry.qry(c + 1, r)}));
                }
            }
        } else {
            int j = qs[i][2];
            if (zero[j] <= i) {
                cout << "NO\n";
            } else if (one[j] <= i) {
                cout << "YES\n";
            } else {
                cout << "N/A\n";
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}