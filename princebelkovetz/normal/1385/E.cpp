#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-8;
void ts(int v, vector <vector <int>>& adj, vector <bool>& used, vector <int> &topsort) {
    used[v] = true;
    for (auto u : adj[v]) {
        if (used[u]) continue;
        ts(u, adj, used, topsort);
    }
    topsort.push_back(v);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector <vector <int>> adj(n + 1);
        vector <pair <int, int>> a;
        vector <bool> used(n + 1);
        vector <int> topsort, ind(n + 1);
        for (int i = 0; i < m; ++i) {
            int t, u, v; cin >> t >> u >> v;
            if (t) adj[u].push_back(v);
            else
                a.push_back({ u, v });
        }
        for (int i = 1; i <= n; ++i) {
            if (used[i]) continue;
            ts(i, adj, used, topsort);
        }
        reverse(topsort.begin(), topsort.end());
        for (int i = 0; i < n; ++i) ind[topsort[i]] = i;
        for (auto x : a) {
            if (ind[x.second] < ind[x.first]) 
                swap(x.first, x.second);
            adj[x.first].push_back(x.second);
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i) 
            for (auto u : adj[i]) 
                if (ind[u] < ind[i]) flag = false;
        if (flag) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                for (auto u : adj[i])
                    cout << i << " " << u << endl;
        }
        else cout << "NO\n";
        
    }

}