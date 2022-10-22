#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int f = 0;
    int cnt = 0;
    while (f < n) {
        int last = arr[f] - 1;
        while (f != last) {
            f++;
            last = max(last, arr[f] - 1);
        }
        f++;
        cnt++;
    }
    cout << cnt;
    return 0;
}