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

const int MOD = 1e9 + 7;
const int N = 1e6 + 239;

ll fact[N];
ll revfact[N];

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

ll inv(ll a) {
    return binpow(a, MOD - 2);
}

ll c(int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        return 0;
    }
    return fact[n] * revfact[k] % MOD * revfact[n - k] % MOD;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int k;
    cin >> k;
    fact[0] = revfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        revfact[i] = inv(fact[i]);
    }
    ll ans = 1;
    for (int l = 1; n >= l && n - (k - 1) * (l - 1) >= l; l++) {
        ans = (ans + c(n - (k - 1) * (l - 1), l) * inv(c(n, l))) % MOD;
    }
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
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