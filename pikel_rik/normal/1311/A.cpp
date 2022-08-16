#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << "0\n";
            continue;
        }

        if (a > b) {
            if ((a - b) % 2 == 0)
                cout << "1\n";
            else cout << "2\n";
        }
        else {
            if ((b - a) % 2 != 0)
                cout << "1\n";
            else cout << "2\n";
        }
    }
    return 0;
}