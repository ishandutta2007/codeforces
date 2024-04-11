#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        a.erase(unique(a.begin(), a.end()), a.end());

        if (k == 1 and a.size() > 1) {
            cout << "-1\n";
        } else {
            if (a.size() <= k) {
                cout << "1\n";
            } else {
                int ans = 1 + ((int)a.size() - 2) / (k - 1);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}