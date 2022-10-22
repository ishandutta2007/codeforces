#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = n; i < 2 * n; ++i) {
        arr[i] = arr[i - n];
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (arr[i]) {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << min(ans, n);
    return 0;
}