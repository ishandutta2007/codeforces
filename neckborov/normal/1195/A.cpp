#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

using ll = long long;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        p >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a - 1]++;
    }
    int sets = (n + 1) / 2;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += min(sets, c[i] / 2) * 2;
        sets -= min(sets, c[i] / 2);
    }
    cout << ans + sets;
    return 0;
}