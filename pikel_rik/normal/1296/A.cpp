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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &i : a) cin >> i;

        int sum = accumulate(a.begin(), a.end(), 0);

        bool f1 = false, f2 = false;
        for (int i = 0; i < n; i++) {
            f1 |= a[i] % 2 == 0;
            f2 |= a[i] % 2 != 0;
        }

        if (sum % 2 != 0 or (f1 and f2))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}