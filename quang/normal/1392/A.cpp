#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int maxVal = 0, minVal = 2e9;
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            maxVal = max(maxVal, u);
            minVal = min(minVal, u);
        }
        if (maxVal == minVal) cout << n << '\n';
        else cout << 1 << '\n';
    }   
    return 0;
}