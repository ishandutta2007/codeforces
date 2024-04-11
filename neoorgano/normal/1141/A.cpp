#include <bits/stdc++.h>
using namespace std;

main() {
    int n, m;
    cin >> n >> m;
    int k = m / n;
    if (k * n != m) {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while (k % 2 == 0) {
        cnt++;
        k /= 2;
    }
    while (k % 3 == 0) {
        cnt++;
        k /= 3;
    }
    if (k != 1) {
        cout << -1;
    } else {
        cout << cnt;
    }
    return 0;
}