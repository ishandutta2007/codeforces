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

const int inf = 2e9 + 3, mod = 998244353;
const int max_n = 4e5 + 3;

int n;
vector<int> gr[max_n];

int dfs(int v, int k, int pr = -1) {
    int res = 0;
    for (int to : gr[v]) {
        if (to == pr) continue;
        int num = dfs(to, k, v);
        if (num > 1) return 2;
        res += !num;
    }
    if ((res + 1) % k > 1) return 2;
    return !((res + 1) % k);
}

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        gr[v1].pb(v2), gr[v2].pb(v1);
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 0; i < n - 1; ++i)
        dp[1] = dp[1] * 2 % mod;

    for (int k = 2; k <= n; ++k) {
        if ((n - 1) % k == 0) {
            if (dfs(0, k) == 0) dp[k] = 1;
        }
    }
    for (int k = n; k >= 1; --k) {
        for (int i = 2 * k; i <= n; i += k)
            dp[k] -= dp[i];
        dp[k] = (dp[k] % mod + mod) % mod;
    }
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << " ";
    cout << endl;
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