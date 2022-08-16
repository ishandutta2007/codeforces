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


template<class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,0,R) rep(c,0,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int d, int l, int r) {
        d++, r++;
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c, --c;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] < a[j]) {
                m[i][j]++;
            }
        }
    }
    SubMatrix sub(m);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i+2; j < n; j++) {
            if (a[i] > a[j]) {
                ans += sub.sum(0, i-1, i+1, j-1);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}