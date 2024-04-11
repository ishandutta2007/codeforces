#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr, arr + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        cout << s - arr[n - q] << endl;
    }
    return 0;
}