#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define L first
#define R second

const LL INF = 1e18;
const int maxn = 1e5 + 10;
vector<pii> adj[maxn];
LL dis[maxn];
int par[maxn];
bool inq[maxn];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fi, se, th;
        cin >> fi >> se >> th;
        fi--, se--;
        adj[fi].push_back(pii(se, th));
        adj[se].push_back(pii(fi, th));
    }
    fill(dis, dis + n, INF);
    fill(par, par + n, -1);

    queue<int> q;

    dis[0] = 0;
    q.push(0);
    inq[0] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();
        inq[u] = false;

        if (dis[u] > dis[n - 1])
            continue;

        for (pii e: adj[u]) {
            int v = e.L;
            int w = e.R;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                par[v] = u;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    if (par[n - 1] == -1)
        return cout << -1 << endl, 0;
    vector<int> path;
    int u = n - 1;
    while (par[u] != -1) {
        path.push_back(u);
        u = par[u];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (auto u: path)
        cout << u + 1 << ' ';
    cout << endl;
    return 0;
}