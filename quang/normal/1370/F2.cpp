#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T>
struct Tree {
    int n;
    vector<vector<pair<int, T>>> adj;
    vector<int> posIn;
    vector<int> posOut;
    vector<int> sz;
    vector<int> lv;
    vector<T> dist;
    vector<vector<int>> par;
    vector<int> order;
 
    Tree(int n = -1) : n(n) {
        adj.assign(n + 1, vector<pair<int, T>>());
        posIn.assign(n + 1, 0);
        posOut.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        lv.assign(n + 1, 0);
        dist.assign(n + 1, 0);
        if (n > 0) par.assign((int)log2(n) + 1, vector<int>(n + 1, 0));
        order.assign(1, 0);
    }
 
    void addEdge(int u, int v, T cost = 1) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
 
    void dfs(int u, int p) {
        posIn[u] = order.size();
        order.push_back(u);
        sz[u] = 1;
        lv[u] = lv[p] + 1;
        par[0][u] = p;
        for (int i = 1; i < par.size(); i++) par[i][u] = par[i - 1][par[i - 1][u]];
 
        for (auto e : adj[u]) {
            int v = e.first;
            T cost = e.second;
            if (v == p) continue;
            dist[v] = dist[u] + cost;
            dfs(v, u);
            sz[u] += sz[v];
        }
 
        posOut[u] = order.size();
    }
 
    int getPar(int u, int k) {
        for (int i = 0; i < par.size(); i++) {
            if (k >> i & 1) u = par[i][u];
        }
        return u;
    }
 
    int getLCA(int u, int v) {
        if (lv[u] < lv[v]) swap(u, v);
        u = getPar(u, lv[u] - lv[v]);
        if (u == v) return u;
        for (int i = (int)par.size() - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return par[0][u];
    }
 
    // find k-th node in path from u to v
    // k = 0 returns u
    // returns -1 if invalid
    int getNodeFromPath(int u, int v, int k) {
        if (k < 0) return -1;
        int w = getLCA(u, v);
        int hu = lv[u] - lv[w];
        if (k <= hu) return getPar(u, k);
        k -= hu;
        int hv = lv[v] - lv[w];
        if (k > hv) return -1;
        return getPar(v, hv - k);
    }
 
    // true if u is v's ancestor
    bool isAncestor(int u, int v) {
        return posIn[u] <= posIn[v] && posOut[v] <= posOut[u];
    }
};
 
pair<int, int> ask(vector<int> &ls) {
    cout << "? " << ls.size() << ' ';
    for (int u : ls) {
        cout << u << ' ';
    }
    cout << endl;
    pair<int, int> res;
    cin >> res.first >> res.second;
    return res;
}
 
int getBiggestChild(Tree<int> &t, int root) {
    int res = -1;
    for (auto u : t.adj[root]) {
        if (res == -1 || t.sz[u.first] > t.sz[res]) res = u.first;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Tree<int> t(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            t.addEdge(u, v);
        }
        vector<int> ls;
        for (int i = 1; i <= n; i++) {
            ls.push_back(i);
        }
        pair<int, int> now = ask(ls);
        t.dfs(now.first, 0);
 
        int len = now.second;
        int root = now.first;
 
        auto getLv = [&](vector<int> &ls) {
            vector<int> allLv;
            for (int u : ls) {
                allLv.push_back(t.lv[u]);
            }
            sort(allLv.begin(), allLv.end());
            allLv.resize(unique(allLv.begin(), allLv.end()) - allLv.begin());
            return allLv;
        };
 
        int biggestChild = getBiggestChild(t, root);
        vector<int> nextList;
        for (int u : ls) {
            if (!t.isAncestor(biggestChild, u)) nextList.push_back(u);
        }
        ls.swap(nextList);
        // cout << "ls after " << endl;
        //     for (int u : ls) cout << u << ' ';
        //         cout << endl;
        
        while (ls.size() >= 2) {
            vector<int> allLv = getLv(ls);
            int midId = allLv.size() / 2;
            int midlv = allLv[midId];
            vector<int> curList;
            for (int u : ls) {
                if (t.lv[u] == midlv) curList.push_back(u);
            }
            pair<int, int> now = ask(curList);
            int delta = (now.second - len) / 2;
            int u = t.getPar(now.first, delta);
            vector<int> nextList;
            if (delta == 0) {
                for (int v : ls) {
                    if (t.isAncestor(u, v)) nextList.push_back(v);
                }
            } else {
                int w = t.getPar(now.first, delta - 1);
                for (int v : ls) {
                    if (t.isAncestor(u, v) && !t.isAncestor(w, v) && t.lv[v] < midlv) nextList.push_back(v);
                }
            }
            ls.swap(nextList);
            // cout << "ls after " << endl;
            // for (int u : ls) cout << u << ' ';
            //     cout << endl;
        }
 
        assert(ls.size() == 1);
        int ans1 = ls[0];
        int needLv = len - t.lv[ans1] + 2;
 
        ls.clear();
        for (int i = 1; i <= n; i++) {
            if (!t.isAncestor(i, ans1) && t.lv[i] == needLv) ls.push_back(i); 
        }
        pair<int, int> foo;
        if (ls.size() == 0) foo.first = root;
        else if (ls.size() == 1) foo.first = ls[0];
        else foo = ask(ls);
        cout << "! " << ans1 << ' ' << foo.first << endl;
        string verdict;
        cin >> verdict;
        if (verdict == "Incorrect") return 0;
    }   
    return 0;
}