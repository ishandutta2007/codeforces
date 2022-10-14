#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, 2 * max(i + 1, n - i));
            }
        }
        ans = max(ans, n);
        cout << ans << "\n";
    }
    return 0;
}