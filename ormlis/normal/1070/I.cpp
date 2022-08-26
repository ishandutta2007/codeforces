#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 100, SZ = 1e5 + 100;

ll t;

vector<vector<ll>> gr, sv;
ll lst[SZ], dist[SZ], used[SZ], ind = 0;

struct edge {
    ll to, bal;
};

vector<edge> edges;

void add_edge(int u, int v, int c) {
    gr[u].push_back(edges.size());
    edges.push_back({ v, c });
    gr[v].push_back(edges.size());
    edges.push_back({ u, c });
}

bool bfs(ll s, ll t) {
    for (int i = 0; i < ind; i++) {
        dist[i] = INF;
        used[i] = 0;
    }

    dist[s] = 0;
    used[s] = 1;

    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        used[v] = 1;
        q.pop();

        for (auto i : gr[v]) {
            edge e = edges[i];
            if (!used[e.to] && e.bal > 0) {
                dist[e.to] = dist[v] + 1;
                used[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    return (used[t]);
}

ll dfs(int v, int t, ll fl = INF) {
    if (v == t) return fl;
    if (fl == 0) return 0;

    for (; lst[v] < gr[v].size(); lst[v]++) {
        int edge_ind = gr[v][lst[v]];
        if (dist[edges[edge_ind].to] == dist[v] + 1) {
            ll psh = dfs(edges[edge_ind].to, t, min(fl, edges[edge_ind].bal));
            if (psh != 0) {
                edges[edge_ind].bal -= psh;
                edges[edge_ind ^ 1].bal += psh;
                return psh;
            }
        }
    }

    return 0;
}
ll dinic(ll s, ll t) {
    ll flow = 0;

    while (bfs(s, t)) {
        for (int i = 0; i < ind; i++) {
            lst[i] = 0;
        }

        ll k = 1;
        while (k) {
            k = dfs(s, t);
            flow += k;
        }
    }

    return flow;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    edges.clear();

    gr.clear();
    gr.resize(n + m + 2);

    ind = n + m + 2;

    sv.clear();
    sv.resize(n);

    vector<pair<ll, ll>> svd;
    for (int i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
        svd.push_back({ u, v });
    }

    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll left = 0;
        if (sv[i - 1].size() > k) left = 2 * (sv[i - 1].size() - k);

        cnt += left;
        add_edge(0, i, left);
    }

    vector<vector<ll>> chk(n);
    for (int i = 0; i < m; i++) {
        ll u = svd[i].first + 1, v = svd[i].second + 1;
        chk[u - 1].push_back(edges.size());
        add_edge(u, i + n + 1, 1);
        chk[v - 1].push_back(edges.size());
        add_edge(v, i + n + 1, 1);
        add_edge(i + n + 1, n + m + 1, 1);
    }

    if (dinic(0, n + m + 1) != cnt) {
        for (int i = 0; i < m; i++) cout << "0 ";
        cout << "\n";
        return;
    }

    vector<vector<ll>> us(n);

    for (int i = 0; i < chk.size(); i++) {
        for (auto c : chk[i]) {
            if (edges[c].bal == 0) {
                us[i].push_back(edges[c].to - n - 1);
            }
        }
    }

    vector<ll> ans(m);
    ll lstcol = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < us[i].size(); j += 2) {
            ans[us[i][j]] = lstcol;
            ans[us[i][j + 1]] = lstcol;
            lstcol++;
        }
    }
    
    for (auto &c : ans) {
        if (c == 0) {
            c = lstcol;
            lstcol++;
        }
        cout << c << " ";
    }
    cout << "\n";

    return;
}

int main() {
    fastInp;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}