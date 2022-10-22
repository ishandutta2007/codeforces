#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 1 && (n * m) % 2 == 0) {
                    cout << 'B';
                    continue;
                }
                if ((i + j) % 2 == 0) {
                    cout << 'B';
                } else {
                    cout << 'W';
                }
            }
            cout << endl;
        }
    }
    return 0;
}