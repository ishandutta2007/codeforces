#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; ++i) {
            cin >> arr[i];
        }
        bool f = true;
        for (int i = 2; i < k; ++i) {
            if (arr[i] - arr[i - 1] < arr[i - 1] - arr[i - 2]) {
                f = false;
            }
        }
        if (k != 1) {
            int a0 = arr[1] - arr[0];
            if (a0 * (n - k + 1) < arr[0]) {
                f = false;
            }
        }
        if (f) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}