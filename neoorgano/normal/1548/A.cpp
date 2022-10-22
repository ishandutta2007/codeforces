#include <bits/stdc++.h>
using namespace std;

main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    int ans = n;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) {
            swap(u, v);
        }
        cnt[u]++;
        if (cnt[u] == 1) {
            ans--;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 3) {
            cout << ans << "\n";
            continue;
        }
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) {
            swap(u, v);
        }
        cnt[u] += 3 - t * 2;
        if (cnt[u] == 1 && t == 1) {
            ans--;
        }
        if (cnt[u] == 0 && t == 2) {
            ans++;
        }
        /// cout << ans << endl;
    }
    return 0;
}