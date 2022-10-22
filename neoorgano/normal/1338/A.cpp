#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int curmax = -1e9;
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            curmax = max(curmax, arr[i]);
            int k = curmax - arr[i];
            int cnt = 0;
            while (k) {
                cnt++;
                k /= 2;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}