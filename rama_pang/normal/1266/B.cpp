#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        lint x;
        cin >> x;
        if (x > 6 && x % 14 <= 6 && x % 14 >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}