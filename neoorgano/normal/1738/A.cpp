#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        array<vector<int>, 2> arr;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            ans += b[i];
            arr[a[i]].push_back(b[i]);
        }
        sort(arr[0].rbegin(), arr[0].rend());
        sort(arr[1].rbegin(), arr[1].rend());
        if (arr[0].size() > arr[1].size()) {
            swap(arr[0], arr[1]);
        }
        for (int elem : arr[0]) {
            ans += elem;
        }
        for (int i = 0; i < (int)arr[0].size(); ++i) {
            ans += arr[1][i];
        }
        if (arr[0].size() == arr[1].size()) {
            ans -= min(arr[0].back(), arr[1].back());
        }
        cout << ans << endl;
    }
    return 0;
}