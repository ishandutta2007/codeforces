#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


const ld INF = 1e18;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ld> a(n);
    ld z = ld(k) / m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= z;
    }
    ll ans = 0;
    vector<ld> kek(m, INF);
    kek[m - 1] = 0;
    ld sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        for (int j = 0; j < m; j++) {
            if (kek[j] > INF - 1) {
                continue;
            }
            int q = ((i - j) % m + m) % m;
            q = m - q;
            if (q == m) {
                q = 0;
            }
            ans = max(ans, ll(roundl(sum - kek[j] - z * q)));
        }
        kek[i % m] = min(kek[i % m], sum);
    }
    cout << ans;
    return 0;
}