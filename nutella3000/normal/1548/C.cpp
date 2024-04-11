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

const int mod = 1e9 + 7;
const int max_n = 3e6 + 7;
int fact[max_n], refact[max_n];

int binpow(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int rev(int a) { return binpow(a, mod - 2); }

void init() {
    fact[0] = refact[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        fact[i] = i * fact[i - 1] % mod;
        refact[i] = refact[i - 1] * rev(i) % mod;
    }
}

int Cnk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * refact[k] % mod * refact[n - k] % mod;
}

void run() {
    init();
    int n, q;
    cin >> n >> q;

    vector<int> dp(3 * n + 1);

    dp[3 * n] = 1;
    dp[3 * n - 1] = 3 * n;
    for (int i = 3 * n - 2; i >= 1; --i) {
        dp[i] = Cnk(3 * n + 3, i + 3) - 3 * dp[i + 1] - 3 * dp[i + 2];
        dp[i] = (dp[i] % mod + mod) % mod;
    }
    for (int it = 0; it < q; ++it) {
        int v;
        cin >> v;
        cout << dp[v] << endl;
    }
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