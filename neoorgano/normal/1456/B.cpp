#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    if (n > 60) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = i; j < n; ++j) {
            cur ^= arr[j];
            int z = 0;
            for (int k = j + 1; k < n; ++k) {
                z ^= arr[k];
                if (cur > z) {
                    ans = min(ans, k - i - 1);
                }
            }
        }
    }
    if (ans == n) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}