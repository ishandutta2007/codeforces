#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e4+7;

struct mat {
    int n, m;
    vector<vector<double>> a;
    
    mat() {}
    mat(int _n) {
        n = _n, m = _n;
        a.assign(_n, vector<double>(_n));
    }
    mat(int _n, int _m) {
        n = _n, m = _m;
        a.assign(_n, vector<double>(_m));
    }
    friend mat operator * (const mat& a, const mat& b) {
        assert(a.m == b.n);
        mat ans(a.n, b.m);
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < b.n; k++) {
                    ans.a[i][j] += a.a[i][k] * b.a[k][j];
                }
            }
        }
        return ans;
    }
};

mat po(mat a, int p) {
    // cerr << "here\n";
    mat ans(a.n);
    for (int i = 0; i < a.n; i++) ans.a[i][i] = 1;
    for (; p; a = a * a, p >>= 1) if (p & 1)
        ans = ans * a;
    return ans;
}
void solve() {
    int n, x; cin >> n >> x;
    vector<double> a(x + 1); for (auto& c : a) cin >> c;
    int X = x + 1;
    while (__builtin_popcount(X) > 1) X++;

    mat m(X);
    for (int i = 0; i < X; i++) {
        for (int j = 0; j <= x; j++) {
            // cerr << i << ' ' << j << ' ' << a[j] << '\n';
            int nxt = i ^ j;
            m.a[i][nxt] = a[j];
        }
    }
    // for (int i = 0; i < X; i++) {
    //     for (int j = 0; j < X; j++)
    //         cerr << m.a[i][j] << ' ';
    //     cerr << endl;
    // }
    mat start(1, X);
    start.a[0][0] = 1;
    mat ans = po(m, n);
    // for (int i = 0; i < X; i++) {
    //     for (int j = 0; j < X; j++)
    //         cerr << ans.a[i][j] << ' ';
    //     cerr << endl;
    // }
    // cerr << "done2\n";
    ans = start * ans;
    cout << fixed << setprecision(10) << 1 - ans.a[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}