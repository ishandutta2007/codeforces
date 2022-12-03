#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long double ld;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l[2], r[2], t[2];
    cin >> l[0] >> r[0] >> t[0];
    cin >> l[1] >> r[1] >> t[1];
    if (l[0] > l[1]) {
        swap(l[0], l[1]);
        swap(r[0], r[1]);
        swap(t[0], t[1]);
    }
    ll g = gcd(t[0], t[1]);
    ll ans = 0;
    ll kek = (l[1] - l[0] + g - 1) / g;
    --kek;
    for (int i = -2; i <= 2; ++i) {
        ans = max(ans, min(r[0] + kek * g, r[1]) - max(l[0] + kek * g, l[1]) + 1);
        ++kek;
    }
    if (r[0] > r[1]) {
        swap(l[0], l[1]);
        swap(r[0], r[1]);
        swap(t[0], t[1]);
    }
    kek = (r[1] - r[0] + g - 1) / g;
    --kek;
    for (int i = -2; i <= 2; ++i) {
        ans = max(ans, min(r[0] + kek * g, r[1]) - max(l[0] + kek * g, l[1]) + 1);
        ++kek;
    }
    cout << ans;
    return 0;
}