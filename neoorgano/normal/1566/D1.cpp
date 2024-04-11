#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n * m);
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            cin >> arr[i];
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}