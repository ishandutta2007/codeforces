#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

int n, m;
int s, t;
vector<pii> graph[MAXN];
vector<tuple<int, int, int>> edges;
vector<int> now;
bool used[MAXN];

int dfs1(int v, int to) {
    used[v] = true;
    if (to == v) {
        return 1;
    }
    for (auto p: graph[v]) {
        if (!used[p.ff]) {
            now.puba(p.ss);
            if (dfs1(p.ff, to)) {
                return 1;
            }
            now.pop_back();
        }
    }
    return 0;
}

pii best_now;
int depth[MAXN];
int up[MAXN];
int skip[MAXN];

int dfs2(int v, int nowe, int to, int d) {
    depth[v] = d;
    up[v] = d;
    used[v] = 1;
    bool flag = (v == to);
    for (auto p: graph[v]) {
        if (p.ss == nowe) {
            continue;
        }
        if (!used[p.ff] && !skip[p.ss]) {
            flag |= dfs2(p.ff, p.ss, to, d + 1);
            up[v] = min(up[v], up[p.ff]);
        } else if (!skip[p.ss]) {
            up[v] = min(up[v], depth[p.ff]);
        }
    }
    //cerr << v << " " << up[v] << " " << flag << endl;
    if (nowe != -1 && flag && up[v] >= d) {
        best_now = min(best_now, make_pair(get<2>(edges[nowe]), nowe));
    }
    return flag;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    --s; --t;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        graph[a].puba({b, i});
        graph[b].puba({a, i});
        edges.puba(make_tuple(a, b, c));
    }

    dfs1(s, t);

    /*
    for (auto e: now) {
        cerr << e << endl;
    }*/

    if (!used[t]) {
        cout << "0\n0\n";
        return 0;   
    }

    int best = 2e9 + 6;
    vector<int> ans;
    for (auto e: now) {
        skip[e] = true;
        best_now = {1e9 + 8, -1};
        fill(used, used + n, 0);
        fill(depth, depth + n, 0);
        fill(up, up + n, 0);
        dfs2(s, -1, t, 0);
        //cerr << best_now.ff << " " << best_now.ss << endl;
        skip[e] = false;
        if (best_now.ss == -1 && used[t]) {
            continue;
        }
        if (!used[t]) {
            if (best > get<2>(edges[e])) {
                best = get<2>(edges[e]);
                ans = {e};
            }
        } else {
            if (best_now.ff + get<2>(edges[e]) < best) {
                best = best_now.ff + get<2>(edges[e]);
                ans = {e, best_now.ss};
            }
        }
    }

    if (best == 2e9 + 6) {
        cout << "-1\n";
        return 0;
    }

    cout << best << "\n" << szof(ans) << "\n";
    for (auto e: ans) {
        cout << e + 1 << " ";
    }
    cout << "\n";

    return 0;
}