#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1]) {
                ans += (arr[i - 1] - arr[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}