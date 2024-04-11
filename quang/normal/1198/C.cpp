#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500010;
 
int n, m;
vector<pair<int, int>> adj[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        set<int> ind;
        vector<int> matching;
        for (int i = 1; i <= n * 3; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        for (int i = 1; i <= n * 3; i++) {
            int found = -1;
            for (auto u : adj[i]) {
                if (ind.count(u.first)) {
                    ind.erase(u.first);
                    found = u.second;
                    break;
                }
            }
            if (found == -1) ind.insert(i);
            else {
                matching.push_back(found);
            }
        }
        if (matching.size() >= n) {
            cout << "Matching" << '\n';
            for (int i = 0; i < n; i++) {
                cout << matching[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "IndSet" << '\n';
            int cnt = 0;
            for (int u : ind) {
                cnt++;
                if (cnt > n) break;
                cout << u << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}