#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int solve();
// #define TESTCASE
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {
    
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    queue<pair<int, int>> q;
    map<int, int> vis;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        vis[x[i]] = 1;
        q.emplace(x[i], 0);
    }
    vector<int> ans;
    lint dist = 0;
    while (ans.size() < n + m) {
        ans.emplace_back(q.front().first);
        int d = q.front().second;
        q.pop();
        if (d > 0) {
            dist += d;
        }
        if (vis[ans.back() + 1] == 0) {
            vis[ans.back() + 1] = 1;
            q.emplace(ans.back() + 1, d + 1);

        }
        if (vis[ans.back() - 1] == 0) {
            vis[ans.back() - 1] = 1;
            q.emplace(ans.back() - 1, d + 1);
        }
    }

    cout << dist << "\n";
    for (int i = n; i < n + m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}