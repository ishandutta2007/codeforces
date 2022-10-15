// ./b-tree-tag.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N, A, B, da, db,
    dis1[MN], dis2[MN];
vector<int> g[MN];

void dfs(int c, int p, int dis[MN]) {
    for (auto to : g[c]) {
        if (to != p) {
            dis[to] = dis[c] + 1;
            dfs(to, c, dis);
        }
    }
}
int getdis(int c, int p, int end) {
    if (c == end) return 0;
    int res = INF;
    for (auto to : g[c])
        if (to != p)
            res = min(res, getdis(to, c, end)+1);
    return res;
}

void _solve() {
    cin >> N >> A >> B >> da >> db;
    for (auto i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (da*2+1 > db) {
        cout << "Alice\n";
        return;
    }

    if (getdis(A, -1, B) <= da) {
        cout << "Alice\n";
        return;
    }

    dfs(1, -1, dis1);
    int e1 = max_element(dis1+1, dis1+N+1) - dis1;
    fill(dis1, dis1+N+1, 0);
    dfs(e1, -1, dis1);
    int e2 = max_element(dis1+1, dis1+N+1) - dis1;
    dfs(e2, -1, dis2);

    int rad = INF;
    for (auto i = 1; i <= N; i++)
        rad = min(rad, max(dis1[i], dis2[i]));

    if (rad <= da) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
}

void solve() {
    _solve();
    for (auto i = 1; i <= N; i++) {
        dis1[i] = dis2[i] = 0;
        g[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}