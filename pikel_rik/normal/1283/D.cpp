#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, x[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x, x + n);

    set<int> visited;
    for (int i = 0; i < n; i++) {
        visited.insert(x[i]);
    }

    set<pair<int, int>> cur;
    for (int i = 0; i < n; i++) {
        cur.emplace(1, x[i]);
    }

    ll dist = 0;
    vector<int> ans;

    while (ans.size() < m) {
        auto [d, x] = *cur.begin();
        cur.erase(cur.begin());

        if (visited.count(x - d) and visited.count(x + d)) {
            continue;
        }

        if (!visited.count(x - d)) {
            dist += d;
            visited.insert(x - d);
            ans.push_back(x - d);
        } else if (!visited.count(x + d)) {
            dist += d;
            visited.insert(x + d);
            ans.push_back(x + d);
        }

        if (visited.count(x - d) and visited.count(x + d)) {
            cur.emplace(d + 1, x);
        } else {
            cur.emplace(d, x);
        }
    }

    cout << dist << '\n';
    for (int x : ans) cout << x << ' '; cout << '\n';
    return 0;
}