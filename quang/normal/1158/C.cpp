#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int nxt[N];
vector<int> adj[N]; 
int deg[N];
int fail = 0;

void addEdge(int u, int v) {
    if (u == 0 || v == 0 || u == n + 1 || v == n + 1) return;
    adj[u].push_back(v);
    deg[v]++;
}

void go(int l, int r) {
    for (int i = l + 1; i < r && !fail; i++) {
        int now = nxt[i];
        if (now == -1) {
            addEdge(i, l);
            continue;
        }
        if (now == r) {
            addEdge(i, l);
            go(i, r);
            break;
        }
        if (now > r) {
            fail = 1;
            return;
        }
        addEdge(i, nxt[i]);
        go(i, nxt[i]);
        i = nxt[i] - 1;
    }
}

int used[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        fail = 0;
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
            adj[i].clear();
            used[i] = 0;
            res[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> nxt[i];
        }
        go(0, n + 1);
        if (fail) {
            cout << -1 << endl;
            continue;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!deg[i]) {
                q.push(i);
                used[i] = 1;
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res[u] = ++cnt;
            for (int v : adj[u]) {
                deg[v]--;
                if (!deg[v]) {
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
            cout << '\n';
    }
    return 0;
}