#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 1 << 20, mod = 1e9 + 7;

void run() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    int res = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int sum = -a[x][y];
            for (int di = -n; di < n; ++di) {
                int i = x-di, j = y-di;
                if (i >= 0 && j >= 0 && i < n && j < m) sum += a[i][j];
            }
            for (int di = -n; di < n; ++di) {
                int i = x-di, j = y+di;
                if (i >= 0 && j >= 0 && i < n && j < m) sum += a[i][j];
            }

            chmax(res, sum);
        }
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}