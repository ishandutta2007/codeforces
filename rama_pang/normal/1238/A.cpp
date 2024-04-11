#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        lint x, y;
        cin >> x >> y;
        if (x - y == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }


}