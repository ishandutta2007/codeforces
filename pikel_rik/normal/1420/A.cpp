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
        for (int& i : a) cin >> i;

        bool f = true;
        for (int i = 1; i < n; i++) {
            f &= (a[i - 1] > a[i]);
        }

        cout << (f ? "NO" : "YES") << '\n';
    }
    return 0;
}