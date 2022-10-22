#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int a[MAXN], c[MAXN];

main() {
    int n;
    cin >> n;
    vector<array<int, 2>> arr;
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        arr.push_back({a, c});
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = arr[i][0];
        c[i] = arr[i][1];
        ans += c[i];
    }
    int fl = 0;
    int mx = a[0] + c[0];
    int i = 0;
    while (i < n - 1) {
        while (i < n - 1 && a[i + 1] <= mx) {
            i++;
            mx = max(mx, a[i] + c[i]);
        }
        if (i < n - 1) {
            ans += a[i + 1] - mx;
            i++;
            mx = max(mx, a[i] + c[i]);
        }
    }
    cout << ans;
    return 0;
}