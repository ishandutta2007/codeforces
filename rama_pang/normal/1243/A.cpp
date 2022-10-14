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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        reverse(begin(a), end(a));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(i + 1, a[i]));
        }
        cout << ans << "\n";
    }
}