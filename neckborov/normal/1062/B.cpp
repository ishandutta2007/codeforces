#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double ld;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll m = n;
    ll ans = 1;
    ll cnt = 1;
    vector<ll> q;
    for (ll i = 2; i * i <= n; ++i) {
        ll p = 0;
        while (m % i == 0) {
            ++p;
            m /= i;
        }
        if (p) {
            q.push_back(p);
        }
        cnt = max(cnt, p);
        if (p) {
            ans *= i;
        }
    }
    ans *= m;
    if (m > 1) {
        q.push_back(1);
    }
    cout << ans << ' ';
    ll kek = 0;
    ll topkek = 1;
    while (topkek < cnt) {
        topkek <<= 1;
        ++kek;
    }
    for (ll i : q) {
        if (i != topkek) {
            ++kek;
            break;
        }
    }
    cout << kek;
    return 0;
}