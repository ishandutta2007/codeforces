#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int max_n = 2e5 + 3, log_n = 20;

void run() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(4, vector<int>(4));

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++cnt[x % 4][y % 4];
    }
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int c = cnt[i][j];
            res += c * (c - 1) / 2 * (n - c);
            res += c * (c - 1) * (c - 2) / 6;
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}