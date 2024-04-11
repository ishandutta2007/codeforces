#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int x = abs(a - b);
        int res = 0;
        res += x / 5;
        x %= 5;
        res += x / 2;
        x %= 2;
        res += x;
        cout << res << endl;
    }
    return 0;
}