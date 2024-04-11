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

const int inf = 2e9 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3, max_k = 17;

int n, k;
string s;
int nxt[max_n][max_k];

void run() {
    cin >> n >> k >> s;

    for (int j = 0; j < k; ++j)
        nxt[n][j] = n;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            if (s[i] != char('a' + j) && s[i] != '?') nxt[i][j] = i;
            else nxt[i][j] = nxt[i + 1][j];
        }
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<vector<int>> pos(n + 1, vector<int>(k));
        for (int j = 0; j < k; ++j)
            pos[n][j] = inf;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < k; ++j) {
                pos[i][j] = pos[i + 1][j];
                if (nxt[i][j] - i >= mid) pos[i][j] = i + mid;
            }
        }

        vector<int> dp(1 << k, inf);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << k); ++mask) {
            if (dp[mask] == inf) continue;
            for (int i = 0; i < k; ++i) {
                if (mask >> i & 1) continue;
                chkmin(dp[mask | (1 << i)], pos[dp[mask]][i]);
            }
        }
        if (dp[(1 << k) - 1] <= n) l = mid;
        else r = mid;
    }
    cout << l << endl;
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