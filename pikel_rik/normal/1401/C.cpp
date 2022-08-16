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
        for (int i = 0; i < n; i++) cin >> a[i];
        int mn = *min_element(a.begin(), a.end());

        vector<int> b = a;
        sort(b.begin(), b.end());

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            ok &= a[i] % mn == 0;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}