//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int w, h;
    cin >> w >> h;
    if (w < h) {
        swap(w, h);
    }
    ll ans = 1;
    if (1) {
        for (int i = 1; i <= w + h; i++) {
            (ans *= 2) %= mod;
        }
    }
    cout << ans;
    return 0;
}