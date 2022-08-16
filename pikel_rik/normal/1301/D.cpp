#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

vector<pair<int, string>> ans, actual;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < m - 1; i++) {
        ans.emplace_back(n - 1, "D");
        ans.emplace_back(n - 1, "U");
        ans.emplace_back(1, "R");
    }

    ans.emplace_back(n - 1, "D");
    for (int i = 0; i < n - 1; i++) {
        ans.emplace_back(m - 1, "L");
        ans.emplace_back(m - 1, "R");
        ans.emplace_back(1, "U");
    }
    ans.emplace_back(m - 1, "L");

    for (auto& [c, s] : ans) {
        if (c == 0 or k == 0) continue;

        if (k < c) {
            actual.emplace_back(k, s);
            break;
        } else {
            actual.emplace_back(c, s);
            k -= c;
        }
    }

    cout << "YES\n";
    cout << actual.size() << '\n';
    for (auto& [c, s] : actual) {
        cout << c << ' ' << s << '\n';
    }
    return 0;
}