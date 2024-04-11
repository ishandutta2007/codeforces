#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int INF = 1e9, N = 4e5 + 10;
int ed[N];
bool was[N], del[N], used[N];
vector<int> g[N];

struct edge {
    ll c, f;
};

struct Max_Flow {
    vector<vector<pair<int,int>>> g;
    vector<edge> e;
    vector<ll> d;
    vector<int> ind;
    Max_Flow(int n) {
        g.resize(n);
        d.resize(n);
        ind.resize(n);
    }
    void add_edge(int a, int b, ll c) {
        g[a].pb({b, e.size()});
        e.pb({c, 0});
        g[b].pb({a, e.size()});
        e.pb({0, 0});
    }
    bool bfs(int s, int t) {
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        deque<int> q{s};
        while (q.size() > 0) {
            int v = q.front();
            q.pop_front();
            for (auto to : g[v]) {
                if (d[to.first] == INF && e[to.second].f < e[to.second].c) {
                    d[to.first] = d[v] + 1;
                    q.pb(to.first);
                }
            }
        }
        return (d[t] != INF);
    }
    ll dfs(int v, int t, ll mn) {
        if (v == t) {
            return mn;
        }
        while (ind[v] < g[v].size()) {
            auto to = g[v][ind[v]++];
            if (d[to.first] == d[v] + 1 && e[to.second].f < e[to.second].c) {
                ll val = dfs(to.first, t, min(e[to.second].c - e[to.second].f, mn));
                if (val != 0) {
                    e[to.second].f += val;
                    e[to.second ^ 1].f -= val;
                    return val;
                }
            }
        }
        return 0;
    }
    ll MaxFlow(int s, int t) {
        ll ans = 0;
        while (bfs(s, t)) {
            fill(ind.begin(), ind.end(), 0);
            while (1) {
                ll res = dfs(s, t, INF);
                if (res == 0) {
                    break;
                }
                ans += res;
            }
        }
        return ans;
    }
    vector<pair<int,int>> get_matching(int m) {
        vector<pair<int,int>> res;
        for (int i = 0; i < m; i++) {
            for (auto to : g[i]) {
                if (e[to.second].f == 1) {
                    res.pb({i, to.first});
                }
            }
        }
        return res;
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    vector<pair<int,int>> u(m);
    map<pair<int,int>, int> num, good;
    for (int i = 0; i < m; i++) {
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
        u[i].second += n1;
        num[{u[i].first, u[i].second}] = i + 1;
    }
    Max_Flow f(n1 + n2 + 2);
    int s = n1 + n2, t = n1 + n2 + 1;
    for (int i = 0; i < n1; i++) {
        f.add_edge(s, i, 1);
    }
    for (int i = 0; i < n2; i++) {
        f.add_edge(i + n1, t, 1);
    }
    for (int i = 0; i < m; i++) {
        f.add_edge(u[i].first, u[i].second, 1);
    }
    int sz = f.MaxFlow(s, t);
    auto res = f.get_matching(n1);
    for (auto to : res) {
        good[to] = 1;
    }
    for (auto to : u) {
        if (good[to]) {
            g[to.second].pb(to.first);
            ed[to.first] = ed[to.second] = num[to];
            was[to.first] = 1;
        } else {
            g[to.first].pb(to.second);
        }
    }
    deque<int> qu;
    for (int i = 0; i < n1; i++) {
        if (!was[i]) {
            qu.pb(i);
        }
    }
    while (qu.size() > 0) {
        int v = qu.front();
        qu.pop_front();
        used[v] = 1;
        for (auto to : g[v]) {
            if (!used[to]) {
                used[to] = 1;
                qu.pb(to);
            }
        }
    }
    vector<int> arr;
    ll sum = 0;
    for (int i = 0; i < n1; i++) {
        if (!used[i]) {
            arr.pb(i);
            sum += ed[i];
        }
    }
    for (int i = n1; i < n1 + n2; i++) {
        if (used[i]) {
            arr.pb(i);
            sum += ed[i];
        }
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int v = arr.back();
            del[v] = 1;
            sum -= ed[v];
            arr.pop_back();
            cout << 1 << endl;
            if (v < n1) {
                cout << v + 1 << endl;
            } else {
                cout << -(v - n1 + 1) << endl;
            }
            cout << sum << endl;
        } else {
            vector<int> ans;
            for (auto to : res) {
                if (!del[to.first] && !del[to.second]) {
                    ans.pb(num[to]);
                }
            }
            cout << ans.size() << endl;
            for (auto to : ans) {
                cout << to << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}