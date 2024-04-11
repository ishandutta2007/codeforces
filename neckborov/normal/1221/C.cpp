//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        ll c, m, x;
        cin >> c >> m >> x;
        ll l = 0, r = min(c, m) + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll tot = c - mid + m - mid + x;
            if (tot < mid) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << l << '\n';
    }
}