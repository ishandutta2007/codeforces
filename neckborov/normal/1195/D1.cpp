#include <bits/stdc++.h>

using namespace std;


using ll = long long;


const ll mod = 998244353;

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
    vector<int> cnt(11);
    vector<ll> pw(25);
    pw[0] = 1;
    for (int i = 1; i <= 24; i++) {
        (pw[i] = pw[i - 1] * 10) %= mod;
    }
    int n;
    cin >> n;
    vector<int> a(n), len(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int m = a[i];
        for (; m > 0; m /= 10, len[i]++);
        cnt[len[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 10; j++) {
            //lhs
            ll m = a[i];
            for (int k = 1; k <= len[i] + j; k++) {
                if (k % 2 == 0 || (k + 1) / 2 > j) {
                    (ans += cnt[j] * (m % 10) * pw[k - 1]) %= mod;
                    m /= 10;
                }
                if (!m) {
                    break;
                }
            }
            //rhs
            m = a[i];
            for (int k = 1; k <= len[i] + j; k++) {
                if (k % 2 == 1 || k / 2 > j) {
                    (ans += cnt[j] * (m % 10) * pw[k - 1]) %= mod;
                    m /= 10;
                }
                if (!m) {
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}