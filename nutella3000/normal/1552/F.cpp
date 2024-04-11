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
const int max_n = 2e5 + 3;

int n;
int x[max_n], y[max_n], s[max_n];
int dp[max_n], pref[max_n];

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];

        int id = lower_bound(x, x + i + 1, y[i]) - x;
        dp[i] = x[i] - y[i] + (i ? pref[i - 1] : 0) - (id ? pref[id - 1] : 0);
        pref[i] = dp[i] + (i ? pref[i - 1] : 0);
        pref[i] %= mod;
        dp[i] %= mod;
    }
    int res = x[n - 1] + 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1) res += dp[i];
    }
    cout << (res % mod + mod) % mod << endl;
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