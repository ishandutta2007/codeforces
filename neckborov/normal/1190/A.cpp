//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    ll m, k;
    cin >> n >> m >> k;
    vector<ll> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    int it = 0;
    int ans = 0;
    while (it < m) {
        ans++;
        ll top = (p[it] - it) / k * k + k + it;
        while (it < m && p[it] < top) {
            it++;
        }
    }
    cout << ans;
    return 0;
}