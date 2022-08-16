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
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        //x + k * a = y - k * b => k (a + b) = y - x;

        if ((y - x) % (a + b) == 0)
            cout << (y - x) / (a + b) << '\n';
        else cout << "-1\n"; 
    }
    return 0;
}