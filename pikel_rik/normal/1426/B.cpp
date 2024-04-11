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
        int n, m;
        cin >> n >> m;

        bool sym = false;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> a(2, vector<int>(2));
            cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
            if (a[0][1] == a[1][0]) {
                sym = true;
            }
        }

        if (m % 2 != 0 or !sym) {
            cout << "NO\n";
        } else cout << "YES\n";
    }
    return 0;
}