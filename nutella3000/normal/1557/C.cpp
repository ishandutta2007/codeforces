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
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    int pow = binpow(2, n - 1);

    for (int i = 1; i <= k; ++i) {
        dp[i] = (pow - (n % 2 == 0)) * dp[i - 1] % mod;
        if (n % 2 == 1) dp[i] += dp[i - 1];
        else dp[i] += binpow(binpow(2, i - 1), n);
        dp[i] %= mod;
    }
    cout << dp[k] % mod << endl;
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