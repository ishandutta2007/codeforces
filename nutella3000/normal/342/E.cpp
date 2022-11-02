#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 1e5 + 4, log_n = 20;

int n;
vector<int> gr[max_n];
int p[max_n][log_n];
int dist[max_n];
int d[max_n];

void dfs(int v, int pr) {
    p[v][0] = pr;
    for(int i = 1;i < log_n; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
    }
    dist[v] = dist[pr] + 1;

    for(int i : gr[v]) {
        if (i != pr) 
            dfs(i, v);
    }
}

int dis(int a, int b) {
    int res = dist[a] + dist[b];
    for(int k = log_n - 1;k >= 0;k--) {
        if (dist[a] - (1 << k) >= dist[b]) 
            a = p[a][k];
        if (dist[b] - (1 << k) >= dist[a])
            b = p[b][k];
    }

    for(int k = log_n - 1;k >= 0;k--) {
        if (p[a][k] != p[b][k]) {
            a = p[a][k];
            b = p[b][k];
        }
    }
    if (a != b) a = p[a][0];
    return res - 2 * dist[a];
}

void solve() {
    int m;
    cin >> n >> m;

    for(int i = 0;i < n;i++) 
        d[i] = inf;

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    dist[0] = -1;
    dfs(0, 0);

    vector<int> after;
    after.emplace_back(0);

    for(int i = 0;i < m;i++) {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1) 
            after.emplace_back(v);
        else {
            int res = d[v];
            for(int i : after) 
                res = min(res, dis(v, i));

            cout << res << endl;
        }

        if (i % 300 == 0) {
            deque<int> bfs;
            for(int i : after) {
                bfs.emplace_back(i);
                d[i] = 0;
            }
            after.clear();

            while(bfs.size()) {
                int v = bfs.back();
                bfs.pop_back();
                for(int i : gr[v]) {
                    if (d[i] < d[v] + 1) 
                        continue;
                    d[i] = d[v] + 1;
                    bfs.emplace_back(i);
                }
            }
        }
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}