#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <functional>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define cerr if (0) cerr

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

const int MAXN = 3e5 + 10;

int n, m;
set<int> g[MAXN];

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    forn(i, n) {
        g[i].clear();
    }
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    return 1;
}

const int INF = 1e9;

pair<vi, vi> get_d(int s) {
    queue<int> q;
    vi d(n, INF);
    vi prev(n, -1);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if  (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                prev[to] = v;
                q.push(to);
            }
        }
    } 
    return mp(d, prev);
}

bool solve() {
    vi ans;
    vi d;
    vi prev;
    tie(d, prev) = get_d(0);

    auto upd = [&](vi cur) {
        if  (ans.empty() || (!cur.empty() && sz(cur) < sz(ans))) {
            ans = cur;
        }
    };

    eprintf("d:\n");
    forn(v, n) {
        eprintf("%d ", d[v]);
    }
    eprintf("\n");

    if  (d[n - 1] < INF) {
        vi cur;
        int v = n - 1;
        while (v) {
            cur.pb(v);
            v = prev[v];
        }
        cur.pb(0);
        reverse(all(cur));
        upd(cur);
    }

    bool ok = 0;
    forn(v, n) {
        if  (d[v] == 2) {
            vi cur = {0, prev[v], v, 0, n - 1};
            upd(cur);
            ok = 1;
        }
    }

    if  (!ok) {
        forn(v, n) {
            g[v].erase(0);
        }
        g[0].clear();

        vi comp(n, -1);

        function<void(int)> dfs = [&](int v) {
            assert(comp[v] != -1);
            for (int to : g[v]) {
                if  (comp[to] == -1) {
                    comp[to] = comp[v];
                    dfs(to);
                }
            }
        };

        int comps = 0;
        forn(v, n) {
            if (comp[v] == -1) {
                comp[v] = comps++;
                dfs(v);
            }
        }

        vi sz_comp(comps);
        forn(v, n) {
            ++sz_comp[comp[v]];
        }

        int vv = -1;
        forn(v, n) {
            if  (d[v] != 1) {
                continue;
            }
            eprintf("v=%d, sz=%d, sz_comp=%d\n", v, sz(g[v]), sz_comp[comp[v]]);
            if  (sz(g[v]) != sz_comp[comp[v]] - 1) {
                vv = v;
            }
        }

        if  (vv != -1) {
            vi dd;
            vi pp;
            tie(dd, pp) = get_d(vv);

            bool was = 0;
            forn(u, n) {
                if  (dd[u] == 2) {
                    vi cur = {0, vv, pp[u], u, vv, n - 1};
                    upd(cur);
                    was = 1;
                }
            }
            assert(was);
        }
    }

    if  (ans.empty()) {
        return 0;
    }

    cout << sz(ans) - 1 << endl;
    for (int v : ans) {
        cout << v + 1 << " ";
    }
    cout << endl;
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        bool ok = solve();
        if  (!ok) {
            cout << -1 << endl;
        }
    }

    return 0;
}