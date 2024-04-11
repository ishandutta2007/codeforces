#include <bits/stdc++.h>
using namespace std;

main() {
    cout.precision(15);
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (double)1 / i;
    }
    cout << ans;
    return 0;
}