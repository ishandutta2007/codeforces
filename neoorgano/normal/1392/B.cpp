#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int a = arr[0], b = arr[0];
        for (int i = 1; i < n; ++i) {
            a = max(arr[i], a);
            b = min(arr[i], b);
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = a - arr[i];
        }
        if (k % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                arr[i] = (a - b) - arr[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}