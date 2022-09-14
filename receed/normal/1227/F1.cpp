#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200002, MOD = 998244353;
ll a[N], f[N], rf[N], pk[N];

ll pw(ll x, ll k) {
    ll res = 1;
    for (int i = 30; i >= 0; i--) {
        res = res * res % MOD;
        if (k & (1 << i))
            res = res * x % MOD;
    }
    return res;
}
ll rev(ll x) {
    return pw(x, MOD - 2);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k, r = 0;
    cin >> n >> k;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    f[0] = rf[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
        rf[i] = rev(f[i]);
    }
    rep(i, n)
        cin >> a[i];
    rep(i, n)
        if (a[i] != a[(i + 1) % n])
            r++;
    ll ans = 0, cc;
    for (int i = 0; 2 * i <= r; i++) {
        ans = (ans + f[r] % MOD * rf[i] % MOD * rf[i] % MOD * rf[r - 2 * i] % MOD * pw(k - 2, r - 2 * i) % MOD) % MOD;
    }
    cout << ((pw(k, r) + MOD - ans) % MOD * rf[2] % MOD) * pw(k, n - r) % MOD;
}