#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int GCD = 2520;
// const int GCD = 12;

int n;
int k[N];
vector<int> adj[N];
int sz[N];
int res[N][GCD];
int used[N][GCD];
int visted[N], cntTot;

int go(int u, int val) {
    if (res[u][val] != -1) return res[u][val];
    vector<pair<int, int>> q;
    q.push_back({u, val});
    used[u][val] = 0;
    int found = -1;
    int id = -1;
    while (1) {
        int uu = q.back().first;
        int vall = q.back().second;
        int nxtVal = (vall + k[uu]) % GCD;
        int nxtU = adj[uu][nxtVal % sz[uu]];
        if (res[nxtU][nxtVal] != -1) {
            found = res[nxtU][nxtVal];
            break;
        }
        if (used[nxtU][nxtVal] != -1) {
            id = used[nxtU][nxtVal];
            break;
        }
        used[nxtU][nxtVal] = q.size();
        q.push_back({nxtU, nxtVal});
    }
    if (found != -1) {
        for (auto u : q) {
            res[u.first][u.second] = found;
        }
        return found;
    }
    // cout << "now" << endl;
    // for (auto u : q) {
    //     cout << u.first << ' ' << u.second << endl;
    // }
    assert(id != -1);
    int cnt = 0;
    cntTot++;
    for (int i = id; i < q.size(); i++) {
        int u = q[i].first;
        if (visted[u] < cntTot) {
            visted[u] = cntTot;
            cnt++;
        }
    }
    // cout << "cnt=" << cnt << endl;
    for (auto u : q) {
        res[u.first][u.second] = cnt;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(res, -1, sizeof res);
    memset(used, -1, sizeof used);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] = (k[i] % GCD + GCD) % GCD;
    }
    for (int i = 1; i <= n; i++) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; j++) {
            int u;
            cin >> u;
            adj[i].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < GCD; j++) {
            go(i, j);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        y = (y % GCD + GCD) % GCD;
        cout << res[x][y] << '\n';
    }
    return 0;
}