#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll inv = 0;
    int x = 0;

    vector<vector<int>> q(1, a);

    for (int bit = 29; bit >= 0; bit--) {
        vector<vector<int>> new_q;

        ll inv0 = 0, inv1 = 0;

        while (!q.empty()) {
            auto v = q.back();
            q.pop_back();

            vector<int> v1, v0;

            int c1 = 0, c0 = 0;
            for (auto& i : v) {
                if (i & (1 << bit)) {
                    c1++;
                    inv1 += c0;
                    v1.push_back(i);
                } else {
                    c0++;
                    inv0 += c1;
                    v0.push_back(i);
                }
            }

            if (!v1.empty()) {
                new_q.push_back(v1);
            }
            if (!v0.empty()) {
                new_q.push_back(v0);
            }
        }

        q.swap(new_q);
        if (inv0 <= inv1) {
            inv += inv0;
        } else {
            inv += inv1;
            x |= (1 << bit);
        }
    }
    cout << inv << ' ' << x << '\n';
    return 0;
}