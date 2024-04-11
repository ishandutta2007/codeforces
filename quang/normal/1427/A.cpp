#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &u : a) cin >> u;
        sort(a.begin(), a.end());
        bool f = 0;
        for (int it = 0; it < 2; it++) {
            bool found = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (sum == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cout << "YES\n";
                for (int u : a) cout << u << ' ';
                    cout << '\n';
                f = 1;
                break;
            }
            reverse(a.begin(), a.end());
        }   
        if (!f) {
            cout << "NO\n";
        }
    }
    return 0;
}