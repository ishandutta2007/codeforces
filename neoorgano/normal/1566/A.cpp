#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, s;
        cin >> n >> s;
        cout << s / ((n + 2) / 2) << "\n";
    }
    return 0;
}