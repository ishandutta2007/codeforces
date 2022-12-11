#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            ok = true;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    
    sort(begin(a), end(a));
    for (auto i: a) {
        cout << i << ' ';
    }
}