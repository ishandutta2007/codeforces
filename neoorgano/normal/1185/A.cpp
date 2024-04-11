#include <bits/stdc++.h>
using namespace std;

int arr[3];

main() {
    int a, b, c, d;
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    sort(arr, arr + 3);
    int ans = 0;
    for (int i = 0 ;i < 2; ++i) {
        ans += max(0, d - arr[i + 1] + arr[i]);
    }
    cout << ans;
    return 0;
}