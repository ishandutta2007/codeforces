#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const int inf = INT_MAX;
const int N = 3e5 + 5;

int n, m, ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        set<int>::iterator it = s.lower_bound(l);
        vector<set<int>::iterator> v;

        for (; it != s.end() and *it <= r; it++) {
            if (*it != x) {
                v.push_back(it);
            }
        }

        for (auto it : v) {
            ans[*it] = x;
            s.erase(it);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
    return 0;
}