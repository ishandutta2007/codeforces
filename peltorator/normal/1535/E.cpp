#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int N = 312345;
const int LG = 20;

int binup[LG][N];
int lvl[N];
int dsupr[N];
int dsusiz[N];
int a[N], c[N];
int par[N];
vector<int> g[N];

int findpr(int v) {
    if (dsupr[v] == v) {
        return v;
    } else {
        dsupr[v] = findpr(dsupr[v]);
        return dsupr[v];
    }
}

void unionsets(int v, int u) {
    v = findpr(v);
    u = findpr(u);
    if (v == u) {
        return;
    }
    if (dsusiz[v] < dsusiz[u]) {
        swap(u, v);
    }
    dsusiz[v] += dsusiz[u];
    dsupr[u] = v;
}

int solve() {
    int q;
    if (!(cin >> q)) {
        return 1;
    }
    dsusiz[0] = 1;
    par[0] = 0;
    dsupr[0] = 0;
    for (int i = 0; i < LG; i++) {
        binup[i][0] = 0;
    }
    cin >> a[0] >> c[0];
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> par[i] >> a[i] >> c[i];
            g[par[i]].push_back(i);
            binup[0][i] = par[i];
            lvl[i] = lvl[par[i]] + 1;
            for (int j = 1; j < LG; j++) {
                binup[j][i] = binup[j - 1][binup[j - 1][i]];
            }
            dsupr[i] = i;
            dsusiz[i] = 1;
        } else {
            int v, w;
            cin >> v >> w;
            ll gold = 0, cost = 0;
            int u = 0;
            while (true) {
                if (w == 0) {
                    break;
                }
                if (a[u] != 0) {
                    int take = min(w, a[u]);
                    gold += take;
                    cost += 1LL * take * c[u];
                    a[u] -= take;
                    w -= take;
                    if (a[u] == 0) {
                        if (a[par[u]] == 0) {
                            unionsets(u, par[u]);
                        }
                        for (int to : g[u]) {
                            if (a[to] == 0) {
                                unionsets(u, to);
                            }
                        }
                    }
                    if (w == 0 || u == v) {
                        break;
                    }
                } else if (findpr(u) == findpr(v)) {
                    break;
                }

                int nxt = v;
                for (int j = LG - 1; j >= 0; j--) {
                    int go = binup[j][nxt];
                    if (lvl[go] > lvl[u] && findpr(u) != findpr(go)) {
                        nxt = go;
                    }
                }
                u = nxt;
            }
            cout << gold << ' ' << cost << endl;
        }
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}