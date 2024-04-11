#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e6;
int arr[MAXN];

main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int ans = 0, cur = 0;
    int x = -1;
    for (int i = 0; i < n; ++i) {
        ans += cur;
        cur += arr[i];
        if (cur < 0) {
            arr[i] = cur;
            x = i;
            break;
        }
    }
    if (x == -1) {
        cout << ans;
        return 0;
    }
    sort(arr + x, arr + n);
    for (int i = 0; i < n; ++i) {
        for (int j = x + i * (k + 1); j < min(n, x + (i + 1) * (k + 1)); ++j) {
            /// cout << j << endl;
            ans += arr[j] * i;
        }
    }
    cout << ans;
    return 0;
}