#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % n != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<array<int, 3>> ans;
        for (int i = 1; i < n; ++i) {
            int k = arr[i] % (i + 1);
            k = (i + 1 - k) % (i + 1);
            ans.push_back({1, i + 1, k});
            arr[0] -= k;
            arr[i] += k;
            ans.push_back({i + 1, 1, arr[i] / (i + 1)});
            arr[0] += arr[i];
            arr[i] = 0;
        }
        sum /= n;
        for (int i = 1; i < n; ++i) {
            ans.push_back({1, i + 1, sum});
        }
        cout << ans.size() << '\n';
        for (auto elem : ans) {
            cout << elem[0] << " " << elem[1] << " " << elem[2] << '\n';
        }
    }
    return 0;
}