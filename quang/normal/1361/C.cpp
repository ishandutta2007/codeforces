#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500010;
 
int n;
int a[N], b[N];
 
struct EulerianGraph {
    vector< vector< pair<int, int> > > adj;
    int num_edges;
    vector<vector<int>> ls;
    int n;
 
    EulerianGraph(int n) : n(n) {
        adj.resize(n + 1);
        ls.resize(n + 1);
        num_edges = 0;
    }
 
    void add_edge(int u, int v, int w, bool undirected = true) {
        adj[u].push_back(make_pair(v, w));
        if (undirected) adj[v].push_back(make_pair(u, w));
        num_edges++;
    }
 
    bool get_eulerian_path(int tot, int mask, int flag) {
        vector<pair<int, int>> path, s;
        vector<bool> was(tot + 10, 0);
        
        int id = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 0) continue;
            if (adj[i].size() % 2) return false;
            id = i;
        }
        if (id == -1) return false;
 
        s.push_back({id, -1});
 
        while (!s.empty()) {
            int u;
            int last;
            tie(u, last) = s.back();
            bool found = false;
            while (!adj[u].empty()) {
                int v = adj[u].back().first;
                int e = adj[u].back().second;
                adj[u].pop_back();
                if (was[e]) continue;
                was[e] = true;
                s.push_back({v, e});
                found = true;
                break; 
            }
            if (!found) {
                path.push_back({u, last});
                s.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        // for (auto u : path) cout << u.first << ' ' << u.second << endl;
 
        vector<int> res;
        res.reserve(tot * 2);
        for (int i = 1; i < path.size(); i++) {
            int cur = path[i].second;
            int u = path[i - 1].first;
            int v = path[i].first;
            if (u == (a[cur] & mask)) {
                res.push_back(cur * 2 - 1);
                res.push_back(cur * 2);
            } else {
                res.push_back(cur * 2);
                res.push_back(cur * 2 - 1);
            }
            // while (!ls[v].empty()) {
            //     int val = ls[v].back();
            //     ls[v].pop_back();
            //     res.push_back(val * 2 - 1);
            //     res.push_back(val * 2);
            // }
        }
 
        if (flag) {
            for (int i = 1; i + 1 < res.size(); i += 2) {
                int u = (res[i] % 2) ? a[(res[i] + 1) / 2] : b[(res[i] + 1) / 2];
                int v = (res[i + 1] % 2) ? a[(res[i + 1] + 1) / 2] : b[(res[i + 1] + 1) / 2];
                assert((u & mask) == (v & mask));
            }
            int u = (res[0] % 2) ? a[(res[0] + 1) / 2] : b[(res[0] + 1) / 2];
            int v = (res.back() % 2) ? a[(res.back() + 1) / 2] : b[(res.back() + 1) / 2];
            assert((u & mask) == (v & mask));
            for (int u : res) cout << u << ' ';
                cout << endl;
        }
        return res.size() == tot * 2;
    }
};
 
bool check(int mid, int flag = 0) {
    int mask = (1 << mid) - 1;
    EulerianGraph e(1 << mid);
    // set<int> s;
    for (int i = 1; i <= n; i++) {
        int u = a[i] & mask;
        int v = b[i] & mask;
        // if (u == v) {
        //     // e.ls[u].push_back(i);
        // } else {
        //     e.add_edge(u, v, i);
        // }
        e.add_edge(u, v, i);
 
        // s.insert(u);
        // s.insert(v);
        // while (s.size() > 2) s.erase(s.begin());
    }
 
    // if (s.size() == 1) {
    //     if (flag) {
    //         for (int i = 1; i <= n * 2; i++) {
    //             cout << i << ' ';
    //         }
    //         cout << endl;
    //     }
    //     return true;
    // }
    // else {
        return e.get_eulerian_path(n, mask, flag);
    // }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    // int best = 0;
    // for (int i = 1; i <= 20; i++) {
    //     if (check(i)) best = i;
    // }
    // cout << best << '\n';
    // check(best, 1);
    if (n == 1) {
        int u = a[1] ^ b[1];
        if (u == 0) cout << 20 << endl;
        else cout << __builtin_ctz(u) << endl;
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
 
    int low = -1, high = 21;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(mid)) low = mid;
        else high = mid;
    }
    cout << low << '\n';
    check(low, 1);
    return 0;
}