#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N], pos[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<pair<int, int>> res;
    res.reserve(3 * n);

    auto go = [&](int u, int v) {
        swap(a[u], a[v]);
        swap(pos[a[u]], pos[a[v]]);
        res.push_back({u, v});
    };
    for (int i = 2; i <= n / 2; i++) {
        if (pos[i] == i) continue;
        if (pos[i] > n / 2) {
            go(1, pos[i]);
        }
        go(pos[i], n);
        go(i, n);
    }
    for (int i = n / 2 + 1; i < n; i++) {
        if (pos[i] == i) continue;
        if (pos[i] <= n / 2) {
            go(pos[i], n);
        }
        go(1, pos[i]);
        go(1, i);
    }
    if (pos[1] != 1) go(1, n);
    cout << res.size() << '\n';
    for (auto u : res) cout << u.first << ' ' << u.second << '\n';
    return 0;
}