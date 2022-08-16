#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int n, p[N];
ll dp[N], ans[N];
vector<int> g[N], suf[N], pref[N];

void dfs(int x) {
    dp[x] = 1;

    suf[x].assign(g[x].size() + 1, 1);
    pref[x].assign(g[x].size() + 1, 1);

    for (int j = 0; j < g[x].size(); j++) {
        int i = g[x][j];
        dfs(i);
        dp[x] = dp[x] * (1 + dp[i]) % mod;
        pref[x][j + 1] = dp[x];
    }
    for (int j = g[x].size() - 1; j >= 0; j--) {
        int i = g[x][j];
        suf[x][j] = (ll)suf[x][j + 1] * (1 + dp[i]) % mod;
    }
}

void reroot(int x, int val) {
    ans[x] = dp[x] * val % mod;
    for (int j = 0; j < g[x].size(); j++) {
        int i = g[x][j];
        reroot(i, (1 + (ll)pref[x][j] * suf[x][j + 1] % mod * val % mod) % mod);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }

    dfs(1);

    ans[1] = dp[1];
    for (int j = 0; j < g[1].size(); j++) {
        int i = g[1][j];
        reroot(i, (1 + (ll)pref[1][j] * suf[1][j + 1]) % mod);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}