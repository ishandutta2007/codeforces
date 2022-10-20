#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int found = 0;
        for (int i = 1; i <= k1; i++) {
            int u;
            cin >> u;
            if (u == n) {
                found = 1;
            }
        }
        for (int i = 1; i <= k2; i++) {
            int u;
            cin >> u;
        }   
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}