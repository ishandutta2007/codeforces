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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int sum = 0, c = 0;
        for (int i = 0; i < n; i++) {
            sum += x - a[i];
            c += x == a[i];
        }

        if (c == n) {
            cout << "0\n";
        } else if (sum == 0 or c > 0) {
            cout << "1\n";
        } else cout << "2\n";
    }
    return 0;
}