#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int n;
    cin >> n;
    vector<array<int, 2>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt00 = 0, cnt20 = 0, cnt02 = 0, cnt22 = 0;
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            int x = arr[i][0] - arr[j][0];
            int y = arr[i][1] - arr[j][1];
            if (x % 4 == 0) {
                if (y % 4 == 0) {
                    cnt00++;
                } else {
                    cnt02++;
                }
            } else {
                if (y % 4 == 0) {
                    cnt20++;
                } else {
                    cnt22++;
                }
            }
        }
        ans += cnt00 * (cnt00 - 1) / 2;
        ans += cnt00 * (cnt02 + cnt20 + cnt22);
        ans += cnt20 * (cnt20 - 1) / 2;
        ans += cnt02 * (cnt02 - 1) / 2;
        ans += cnt22 * (cnt22 - 1) / 2;
    }
    cout << ans / 3 << endl;
    return 0;
}