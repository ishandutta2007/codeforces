#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

ll mod(ll x) {
    x %= (int) 1e9 + 7;

    if (x < 0) {
        x += (int) 1e9 + 7;
    }

    return x;
}

ll cnk_table[4001][4001];
ll cnk(ll n, ll k) {
    if (n < 0 || k < 0 || k > n) {
        return 0;
    }

    if (k == 0 || k == n) {
        return 1;
    }

    if (cnk_table[n][k] != 0) {
        return cnk_table[n][k];
    }

    cnk_table[n][k] = cnk(n - 1, k - 1) + cnk(n - 1, k);
    cnk_table[n][k] = mod(cnk_table[n][k]);
    return cnk_table[n][k];
}

int n;
ll d[4001][4001];

int main() {
    ios::sync_with_stdio(false);
#ifndef NDEBUG
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    d[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i][j] = d[i - 1][j] * j + d[i - 1][j - 1];
            d[i][j] = mod(d[i][j]);
        }
    }

    ll ans = 1;
    for (int k = 1; k < n; k++) {
        ll eq = 0;
        for (int i = 0; i <= k; i++) {
            eq += d[k][i];
            eq = mod(eq);
        }

        ans += mod(cnk(n, n - k) * eq);
        ans = mod(ans);
    }

    cout << ans << "\n";

    return 0;
}