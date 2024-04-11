#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 1e5 + 5;
vector<pii> graph1[MAXN];

int ans[MAXN];
bool used[MAXN];

const int bp = 20;
int binup[bp][MAXN];
int depth[MAXN];
int color[MAXN], len[MAXN];
int type[MAXN];

int dfs(int v, int p, int d, int c, int t) {
    used[v] = true;
    type[v] = t;
    depth[v] = d;
    binup[0][v] = p;
    color[v] = c;
    if (color[p] == color[v]) {
        len[v] = len[p] + 1;
    } else {
        len[v] = 1;
    }
    
    //cerr << v << " " << color[v] << " " << len[v] << " " << depth[v] << endl;

    for (int i = 1; i < bp; ++i) {
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }

    for (pii to : graph1[v]) {
        if (to.ff != p) {
            dfs(to.ff, v, d + 1, to.ss, t);
        }
    }
    return 0;
}

int get_lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    for (int i = bp - 1; i >= 0; --i) {
        if (depth[a] + (1 << i) <= depth[b]) {
            b = binup[i][b];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = bp - 1; i >= 0; --i) {
        if (binup[i][a] != binup[i][b]) {
            a = binup[i][a];
            b = binup[i][b];
        }
    }
    return binup[0][a];
}

int main() {
    //freopen("in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int p, t;
        scanf("%d%d", &p, &t);
        //cerr << p << " " << t << endl;
        --p;
        if (t == 0) {
            graph1[i].puba({p, 0});
            graph1[p].puba({i, 1});
            //cerr << i << " " << p << endl;
        } else if (t == 1) {
            graph1[p].puba({i, 0});
            graph1[i].puba({p, 1});
            //cerr << p << " " << i << endl;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, i, 0, 0, cnt);
            ++cnt;
        }
    }
    
    int q;
    scanf("%d", &q);
    vector<pii> inp;

    for (int i = 0; i < q; ++i) {
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        --u; --v;
        if (t == 1) {
            if (type[u] == type[v]) {
                //cerr << i << endl;
                int lca = get_lca(u, v);
                //cerr << lca << endl;
                bool flag = (lca == u && color[v] == 1 && len[v] >= depth[v] - depth[lca]);
                
                ans[i] = flag;
                //cerr << i << endl;
            }
        } else {
            if (type[u] == type[v]) {
                //cerr << i << endl;
                int lca = get_lca(u, v);
                //cerr << lca << endl;
                bool flag = true;
                if (lca != u) {
                    flag &= (color[u] == 1 && len[u] >= depth[u] - depth[lca]);
                }
                flag &= (v != lca && color[v] == 0 && len[v] >= depth[v] - depth[lca]);
                ans[i] = flag;
                //cerr << i << endl;
            }

        }
        inp.puba({u, v});
    }

    for (int i = 0; i < q; ++i) {
        if (ans[i] && inp[i].ff != inp[i].ss) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}