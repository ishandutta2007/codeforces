#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int a[MAXN], b[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = n, y = n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                x = min(x, i);
            }
            if (a[i] == -1) {
                y = min(y, i);
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        bool ans = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                if (i <= x) {
                    ans = 0;
                    break;
                }
            }
            if (a[i] > b[i]) {
                if (i <= y) {
                    ans = 0;
                    break;
                }
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}