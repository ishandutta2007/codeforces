#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int lst = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = a[i] - '0', y = b[i] - '0';
            if ((x ^ y) == 1) {
                ans += 2;
                lst = -1;
                continue;
            }
            if (x == 0) {
                ans++;
                if (lst == 1) {
                    ans++;
                    lst = -1;
                } else {
                    lst = 0;
                }
            } else {
                if (lst == 0) {
                    ans++;
                    lst = -1;
                } else {
                    lst = 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}