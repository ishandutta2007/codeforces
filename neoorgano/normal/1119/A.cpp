#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int first = n, last;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != arr[0]) {
            last = i;
        }
        if (arr[i] != arr[n - 1]) {
            first = min(i, first);
        }
    }
    cout << max(last, n - 1 - first);
    return 0;
}