#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int b = 1e9;
    int c = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b = min(b, a[i] - c);
        c = max(c, a[i] - b);
        if (b < 0 || b + c != a[i]) {
            ok = false;
        }
    }
    
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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