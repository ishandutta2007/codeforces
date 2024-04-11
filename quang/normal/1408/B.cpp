#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            if (a.empty() || a.back() != u) a.push_back(u);
        }
        if (k == 1) {
            if (a.size() == 1) cout << 1 << '\n';
            else cout << -1 << '\n';
            continue;
        }        
        k--;
        if (a.size() == 1) {
            cout << 1 << '\n';
            continue;
        }
        cout << (a.size() - 2) / k + 1 << '\n';
    }
    return 0;
}