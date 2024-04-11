#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

const int N = (int) 2e5 + 123;

int n;
int m, k;
set<int> g[N];
int deg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
        deg[x]++;
        deg[y]++;
        edges.push_back({x, y});
    }

    int ans = n;
    vector<int> todel;
    vector<bool> used(n + 1, true);
    for (int i = 1; i <= n; i++) {
        if (deg[i] < k) {
            todel.push_back(i);
            used[i] = false;
            ans--;
        }
    }
    vector<int> res;
    for (int i = m; i >= 1; i--) {
        while (!todel.empty()) {
            int v = todel.back();
            todel.pop_back();
            for (int u : g[v]) {
                deg[u]--;
                if (deg[u] < k && used[u]) {
                    todel.push_back(u);
                    used[u] = false;
                    ans--;
                }
            }
        }
        res.push_back(ans);
        auto &[x, y] = edges[i - 1];
        g[x].erase(y);
        g[y].erase(x);
        if (used[y]) deg[x]--;
        if (used[x]) deg[y]--;
        if (deg[x] < k && used[x]) {
            todel.push_back(x);
            used[x] = false;
            ans--;
        }
        if (deg[y] < k && used[y]) {
            todel.push_back(y);
            used[y] = false;
            ans--;
        }
    }
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x << "\n";
    }

    return 0;
}