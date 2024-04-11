#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve() {
    int n, m, k; cin >> n >> m >> k; k += 2;
    TwoSat ts(n * k);
    // (i, j) is true iff a[i] >= j
    for (int i = 0; i < n; i++) {
        ts.setValue(i * k + 0);
        ts.setValue(i * k + 1);
        ts.setValue(~(i * k + k - 1));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k; j++) {
            ts.either(i * k + j - 1, ~(i * k + j));
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            // bad if a[i-1] >= j and ~(a[i] >= j)
            // must have ~(a[i-1] >= j) or a[i] >= j
            ts.either(~((i - 1) * k + j), i * k + j);
        }
    }

    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x, --i;
            ts.either(i * k + x + 1, ~(i * k + x));
        } else if (t == 2) {
            int i, j, x; cin >> i >> j >> x, --i, --j;
            for (int a = x; a < k; a++) {
                ts.setValue(~(i * k + a));
                ts.setValue(~(j * k + a));
            }
            for (int a = 0; a < k; a++) {
                int b = x - a + 1;
                if (0 <= b && b < k) {
                    ts.either(~(i * k + a), ~(j * k + b));
                    ts.either(~(j * k + a), ~(i * k + b));
                }
            }
        } else if (t == 3) {
            int i, j, x; cin >> i >> j >> x, --i, --j;
            for (int a = 0; a < k-1; a++) {
                int b = x - a - 1;
                // bad if a[i] <= a and a[j] <= b
                // bad if ~(a[i] >= a+1) and ~(a[j] >= b+1)
                // must have a[i] >= a+1 or a[j] >= b+1
                b = max(b, 0);
                if (b < k-1) {
                    ts.either(i * k + a + 1, j * k + b + 1);
                    ts.either(j * k + a + 1, i * k + b + 1);
                } else {
                    ts.setValue(i * k + a + 1);
                    ts.setValue(j * k + a + 1);
                }
            }
        }
    }
    
    bool ans = ts.solve(); auto pr = ts.values;
    if (!ans) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) if (pr[i * k + j] && !pr[i * k + j + 1]) {
            cout << j << ' ';
            break;
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}