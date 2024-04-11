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
    ll n, k;
    cin >> n >> k;
    ll a = 1;
    ll b = 3;
    ll c = -2 * n - 2 * k;
    ll d = b * b - 4 * a * c;
    ll kek = (-b + sqrtl(d)) / 2;
    cout << n - kek;
    return 0;
}