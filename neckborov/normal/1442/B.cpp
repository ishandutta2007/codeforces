#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> used(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        used[x] = i + 1;
    }
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (!used[a[i]]) continue;
        int kekw = 0;
        if (i && used[a[i - 1]] < used[a[i]]) {
            kekw++;
        }
        if (i + 1 < n && used[a[i + 1]] < used[a[i]]) {
            kekw++;
        }
        ans = ans * kekw % mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}