#include <bits/stdc++.h>
using namespace std;

main() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int f1 = 0;
    int f2 = 1;
    int ans = 1;
    while (f1 < n) {
        while (f2 < n && arr[f2] - arr[f1] <= 5) {
            f2++;
        }
        ans = max(ans, f2 - f1);
        f1++;
    }
    cout << ans;
    return 0;
}