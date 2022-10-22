#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        k = min(k, m - 1);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int len1 = n - k;
        int len2 = n - m + 1;
        int ans = 0;
        for (int s = 0; s <= n - len1; ++s) {
            int res = 1e9;
            for (int f = s; f <= s + len1 - len2; ++f) {
                res = min(res, max(arr[f], arr[f + len2 - 1]));
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}