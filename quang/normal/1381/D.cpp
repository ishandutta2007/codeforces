#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a, b;
vector<int> adj[N];
vector<int> path;
bool isInPath[N];
bool isGood[N];
int len[N];

bool findPath(int u, int p) {
    path.push_back(u);
    if (u == b) return 1;

    for (int v : adj[u]) {
        if (v == p) continue;
        if (findPath(v, u)) return 1;
    }

    path.pop_back();
    return 0;
}

bool dfs(int u, int p) {
    int res = 0;
    pair<int, int> maxLen(0, 0);
    for (int v : adj[u]) {
        if (v == p || isInPath[v]) continue;
        res |= dfs(v, u);
        int curLen = len[v];
        if (maxLen.first < curLen) swap(curLen, maxLen.first);
        if (maxLen.second < curLen) swap(curLen, maxLen.second);
    }
    maxLen.first++, maxLen.second++;
    len[u] = maxLen.first;
    if (maxLen.first >= path.size() && maxLen.second >= path.size()) res = 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b;
        
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        fill(isInPath, isInPath + n + 1, 0);
        fill(isGood, isGood + n + 1, 0);
        path.clear();

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        findPath(a, 0);
        for (int u : path) {
            isInPath[u] = 1;
        }
        for (int u : path) {
            isGood[u] = dfs(u, 0);
        }
        
        int l = 0, r = path.size() - 1;
        int curL = l, curR = r;
        while (curL <= l || curR >= r) {
            while (curL <= l && curL < path.size()) {
                int foo = max(1, (int)path.size() - len[path[curL]]);
                r = min(r, curL + foo);
                curL++;
            }

            while (curR >= r && curR >= 0) {
                int foo = max(1, (int)path.size() - len[path[curR]]);
                l = max(l, curR - foo);
                curR--;
            }
        }

        int res = 0;
        for (int i = 0; i <= l; i++) {
            if (isGood[path[i]]) res = 1;
        }
        for (int i = r; i < path.size(); i++) {
            if (isGood[path[i]]) res = 1;
        }
        if (r <= l) {
            for (int i = r; i <= l; i++) {
                if (len[path[i]] >= path.size()) res = 1;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
    return 0;
}