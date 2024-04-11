#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

int n, m, s, k;
vector<int> has[110];
vector<int> adj[N];
int res[N][110];
queue<pair<int, int> > q;
int used[N];

void bfs(int val) {
    while (!q.empty()) {
        q.pop();
    }
    memset(used, 0, sizeof used);
    for (int u : has[val]) {
        used[u] = 1;
        q.push(make_pair(u, 0));
    }
    while (!q.empty()) {
        int u, len;
        tie(u, len) = q.front();
        // cerr << u << " " << len << endl;
        res[u][val] = len;
        q.pop();
        for (int v : adj[u]) {
            if (used[v]) {
                continue;
            }
            used[v] = 1;
            q.push(make_pair(v, len + 1));
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        has[u].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        // cerr << i << endl;
        bfs(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(res[i] + 1, res[i] + k + 1);
        // printf("%d\n", i);
        // for (int j = 1; j <= k; j++) {
        //     printf("%d ", res[i][j]);
        // }
        // printf("\n");
        long long foo = 0ll;
        for (int j = 1; j <= s; j++) {
            foo += res[i][j];
        }
        printf("%lld ", foo);
    }
    printf("\n");
    return 0;
}