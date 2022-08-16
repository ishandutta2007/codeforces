#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (auto &x : a) cin >> x;

        string s;
        cin >> s;

        map<string, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m) {
                    mp[a[i].substr(j, 2)] = make_pair(i, j);
                }
                if (j + 2 < m) {
                    mp[a[i].substr(j, 3)] = make_pair(i, j);
                }
            }
        }

        const tuple<int, int, int> invalid = make_tuple(-1, -1, -1);

        vector<tuple<int, int, int>> parent(m + 1, invalid);
        auto dfs = [&](int u, auto &&self) -> void {
            map<string, pair<int, int>>::iterator it;
            if (u + 2 <= m && (it = mp.find(s.substr(u, 2)), it != mp.end()) && parent[u + 2] == invalid) {
                parent[u + 2] = make_tuple(it->second.first, it->second.second, 2);
                self(u + 2, self);
            }
            if (u + 3 <= m && (it = mp.find(s.substr(u, 3)), it != mp.end()) && parent[u + 3] == invalid) {
                parent[u + 3] = make_tuple(it->second.first, it->second.second, 3);
                self(u + 3, self);
            }
        };

        dfs(0, dfs);

        if (parent[m] == invalid) {
            cout << "-1\n";
            continue;
        }

        vector<tuple<int, int, int>> ans;
        for (int u = m; u > 0;) {
            auto [i, j, len] = parent[u];
            ans.emplace_back(j, j + len - 1, i);
            u -= len;
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (auto [l, r, i] : ans) {
            cout << l + 1 << ' ' << r + 1 << ' ' << i + 1 << '\n';
        }
    }
    return 0;
}