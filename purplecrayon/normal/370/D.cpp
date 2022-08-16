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
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,0,R) rep(c,0,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int l, int d, int r) {
        if (r < l || d < u) return T();
        d++, r++;
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};


void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n); for (auto& s : g) cin >> s;
    int max_row = -1, min_row = n, max_col = -1, min_col = m;
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'w') {
                max_row = max(max_row, i);
                min_row = min(min_row, i);
                max_col = max(max_col, j);
                min_col = min(min_col, j);
                a[i][j] = 1;
            }
        }
    }
    int len = max(max_row - min_row + 1, max_col - min_col + 1);
    if (len == 1) {
        for (auto s : g) cout << s << '\n';
        return;
    }

    SubMatrix mat(a);
    int tot = mat.sum(0, 0, n-1, m-1);
    for (int i = 0; i + len <= n; i++) {
        for (int j = 0; j + len <= m; j++) {
            int me = mat.sum(i, j, i + len - 1, j + len - 1);
            me -= mat.sum(i + 1, j + 1, i + len - 2, j + len - 2);
            if (me == tot) {
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        if (g[a][b] == 'w') {
                            cout << 'w';
                            continue;
                        }
                        if ((i <= a && a <= i + len - 1) && (j <= b && b <= j + len - 1) && (i == a || j == b || a == i + len - 1 || b == j + len - 1)) {
                            cout << '+';
                            continue;
                        }
                        cout << '.';
                    }
                    cout << '\n';
                }
                return;
            }
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}