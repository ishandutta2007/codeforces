#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
int h[N];
vector<int> adj[N], revAdj[N];
int lv[N];
int inDeg[N];
int deg[N];
int cnt[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
        inDeg[u]++;
    }
    queue<int> q;
    vector<int> nimSum;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            cnt[lv[v]]++;
        }
        lv[u] = 0;
        while (cnt[lv[u]] > 0) {
            lv[u]++;
        }
        for (int v : adj[u]) {
            cnt[lv[v]]--;
        }
        if (nimSum.size() <= lv[u]) {
            nimSum.push_back(h[u]);
        } else {
            nimSum[lv[u]] ^= h[u];
        }

        for (int v : revAdj[u]) {
            inDeg[v]--;
            if (!inDeg[v]) {
                q.push(v);
            }
        }
    }
    int found = -1;
    for (int i = 0; i < nimSum.size(); i++) {
        if (nimSum[i] > 0) {
            found = i;
        }
    }
    if (found == -1) {
        cout << "LOSE" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        res[i] = h[i];
    }
    cout << "WIN" << endl;
    for (int i = 1; i <= n; i++) {
        if (lv[i] == found) {
            int need = nimSum[found] ^ h[i];
            if (need < h[i]) {
                res[i] = need;
                nimSum[found] = 0;
                for (int v : adj[i]) {
                    int need = nimSum[lv[v]] ^ h[v];
                    nimSum[lv[v]] = 0;
                    res[v] = need;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}