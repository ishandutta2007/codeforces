#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int arr1[MAXN], arr2[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }
    map<pair<int, int>, int> m;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int d = __gcd(arr1[i], arr2[i]);
        if (arr1[i] == 0 && arr2[i] != 0) {
            continue;
        }
        if (arr1[i] == 0 && arr2[i] == 0) {
            cnt++;
            continue;
        }
        arr1[i] /= d;
        arr2[i] /= d;
        m[{arr1[i], arr2[i]}]++;
        ans = max(ans, m[{arr1[i], arr2[i]}]);
    }
    for (int i = 0; i < n; ++i) {
        // cout << arr2[i] << " ";
    }
    cout << ans + cnt;
    return 0;
}