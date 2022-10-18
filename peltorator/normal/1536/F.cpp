#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int N = 1123456;

ll fact[N], factinv[N];

ll c(int n, int k) {
    if (n < k || k < 0) {
        return 0;
    }
    return fact[n] * factinv[k] % MOD * factinv[n - k] % MOD;
}

ll binpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    fact[0] = factinv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        factinv[i] = inv(fact[i]);
    }
    ll ans = 0;
    for (int i = 0; i <= n / 2; i++) {
        if ((n - i) % 2 == 0) {
            ans = (ans + c(n - i, i) * fact[n - 1 - i]) % MOD;
        }
    }
    cout << ans * 2LL * n % MOD << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}