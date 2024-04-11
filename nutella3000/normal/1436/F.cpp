#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair

const int inf = 1e9;
const int max_n = 1e5 + 3, mod = 998244353;

int sum(int a, int b) {
    int r = a + b;
    if (r >= mod) r -= mod;
    if (r < 0) r += mod;
    return (r % mod + mod) % mod;
}

int mul(int a, int b) { return (a * b % mod + mod) % mod; }

int mul(vector<int> a) {
    int r = 1;
    for (int i : a)
        r = r % mod * i % mod;
    return (r + mod) % mod;
}

int binpow(int a, int b) {
    if (b < 0) b += mod - 1;
    int res = 1;
    for (; b; b /= 2, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

void run() {
    int n;
    cin >> n;
    vector<int> f(max_n);
    for (int i = 0; i < n; ++i) {
        int v, x;
        cin >> v >> x;
        f[v] = x;
    }

    vector<int> dp(max_n);
    for (int k = 1e5; k >= 1; --k) {
        int cnt = 0, sm = 0, sm2 = 0;
        bool lone = true;
        for (int i = 0; i < max_n; i += k) {
            if (cnt != 0 && f[i] != 0) lone = false;
            cnt += f[i];
            sm = sum(sm, mul(f[i] % mod, i));
            sm2 = sum(sm2, mul({f[i] % mod, i, i}));
        }

        int c = cnt % (mod - 1);
        cnt %= mod;
        //if (k == 2) cout << cnt << " " << sm << " " << sm2 << endl;
        if (!lone || cnt != 1) {
            dp[k] = sum(mul({sm % mod, sm % mod, sum(mul(cnt - 2, binpow(2, c - 3)), binpow(2, c - 2))}), 
                mul({sm2, cnt - 2, binpow(2, c - 3)}));
        }
        for (int i = 2 * k; i < max_n; i += k)
            dp[k] = sum(dp[k], mod - dp[i]);
    }

    //cout << dp[2] << endl;
    cout << dp[1] % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);

    run();
}