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
const int max_n = 101;

int n, k;
vector<int> gr[max_n];

void dfs(int v, int pr, int deep, vector<int>& cnt) {
    ++cnt[deep];
    for (int to : gr[v]) {
        if (to != pr)
            dfs(to, v, deep + 1, cnt);
    }
}

void run() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2; --v1, --v2;
        gr[v1].pb(v2), gr[v2].pb(v1);
    }
    if (k == 2) {
        cout << n * (n - 1) / 2 << endl;
        return;
    }
    int res = 0;
    for (int st = 0; st < n; ++st) {
        vector<vector<int>> cnt;
        for (int to : gr[st]) {
            cnt.pb(vector<int>(n));
            dfs(to, st, 0, cnt.back());
        }
        for (int d = 0; d < n; ++d) {
            vector<int> dp(k + 1);
            dp[0] = 1;
            for (int i = 0; i < size(cnt); ++i) {
                if (!cnt[i][d]) continue;
                for (int j = k - 1; j >= 0; --j) {
                    dp[j + 1] += dp[j] * cnt[i][d];
                    while (dp[j + 1] >= mod) dp[j + 1] -= mod;
                }
            }
            res += dp[k];
        }
    }
    cout << res % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}