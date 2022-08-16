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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> ans(n);
        int mx = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((y - x) % (j - i)) continue;

                vector<int> v(n);
                int diff = (y - x) / (j - i);
                v[i] = x;
                for (int k = i - 1; k >= 0; k--)
                    v[k] = v[k + 1] - diff;
                for (int k = i + 1; k < n; k++)
                    v[k] = v[k - 1] + diff;

                if (v.front() > 0 and v.back() < mx) {
                    mx = v.back();
                    ans = v;
                }
            }
        }

        for (int i : ans) cout << i << " ";
        cout << '\n';
    }
    return 0;
}