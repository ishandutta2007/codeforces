#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int, greater<int>> a;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (b % 2 == 0) {
                a.emplace(b);
            }
        }
        
        int ans = 0;
        while (!a.empty()) {
            int k = *a.begin();
            a.erase(a.begin());
            ans++;
            k /= 2;
            if (k % 2 == 1) {
                continue;
            } else {
                a.emplace(k);
            }
        }
        cout << ans << "\n";
    }

}