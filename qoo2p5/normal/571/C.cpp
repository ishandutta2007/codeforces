#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

struct edge {
    int to, var, id;

    edge() {}
    edge(int to, int var, int id) : to(to), var(var), id(id) {}
};

int n, m;
vector<vector<int>> dis;
vector<vector<pair<int, int>>> where;
vector<vector<edge>> g;
vector<int> color;
vector<bool> visited;
vector<bool> visited_edge1;
vector<bool> visited_edge2;
vector<int> cnt[2];
vector<int> ans;
vector<bool> need;

int find_cycle(int v, bool first=true) {
    color[v] = 1;

    if ((g[v].size() == 0 && first) || !need[v]) {
        return v;
    }

    for (auto edge : g[v]) {
        if (visited_edge1[edge.id]) {
            continue;
        }

        visited_edge1[edge.id] = true;

        if (color[edge.to] == 1) {
            return edge.to;
        } else if (color[edge.to] == 0) {
            int res = find_cycle(edge.to, false);
            if (res != -1) {
                return res;
            }
        }
    }

    color[v] = 2;
    return -1;
}

void dfs(int v, bool first=true) {
    visited[v] = true;

    if (g[v].size() == 0 && first) {
        for (int var : dis[v]) {
            ans[abs(var)] = var > 0;
        }
    }

    for (auto edge : g[v]) {
        if (visited_edge2[edge.id]) {
            continue;
        }

        visited_edge2[edge.id] = true;
        if (!visited[edge.to]) {
            dfs(edge.to, false);
        }

        int sgn;
        if (where[edge.var][0].first == v) {
            sgn = where[edge.var][0].second;
        } else {
            sgn = where[edge.var][1].second;
        }

        ans[edge.var] = sgn < 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    dis.resize(n);
    where.resize(m + 1);
    ans.resize(m + 1);
    g.resize(n);
    color.resize(n);
    visited.resize(n);
    need.resize(n, true);
    for (int i = 0; i < 2; i++) {
        cnt[i].resize(m + 1);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int v;
            cin >> v;
            dis[i].pb(v);
            where[abs(v)].pb(mp(i, v));
            cnt[v > 0][abs(v)]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (cnt[0][i] == 0) {
            ans[i] = 1;
            for (auto j : where[i]) {
                need[j.first] = false;
            }
        } else if (cnt[1][i] == 0) {
            ans[i] = 0;
            for (auto j : where[i]) {
                need[j.first] = false;
            }
        }
    }

    int eid = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt[0][i] == 1 && cnt[1][i] == 1) {
            int a = where[i][0].first;
            int b = where[i][1].first;

            g[a].push_back(edge(b, i, eid));
            g[b].push_back(edge(a, i, eid));
            eid++;
        }
    }

    visited_edge1.resize(eid);
    visited_edge2.resize(eid);

    for (int i = 0; i < n; i++) {
        if (need[i] && color[i] == 0) {
            int cycle_v = find_cycle(i);
            if (cycle_v == -1) {
                cerr << i << endl;
                cout << "NO\n";
                return 0;
            }

            dfs(cycle_v);
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}