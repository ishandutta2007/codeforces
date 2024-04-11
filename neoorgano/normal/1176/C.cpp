#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int arr[MAXN];
int ans[6];

main() {
    int n;
    cin >> n;
    map<int, int> m = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] = m[arr[i]];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            ans[arr[i]]++;
            continue;
        }
        if (ans[arr[i] - 1] == 0) {
            continue;
        }
        ans[arr[i] - 1]--;
        ans[arr[i]]++;
    }
    cout << n - 6 * ans[5];
    return 0;
}