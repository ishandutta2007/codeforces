#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool f = true;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] != arr[0]) {
                f = false;
            }
        }
        if (f) {
            cout << n << "\n";
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}