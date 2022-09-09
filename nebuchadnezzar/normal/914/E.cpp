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

const int MAXN = 2e5 + 5;
string lets;
vector<int> graph[MAXN];
int n;
bool used[MAXN];
int sz[MAXN];
int best[MAXN];
vector<int> visited;

int calc_sz(int v, int p) {
    visited.puba(v);
    sz[v] = 1;
    best[v] = 0;
    for (int to : graph[v]) {
        if (!used[to] && to != p) {
            calc_sz(to, v);
            sz[v] += sz[to];
            best[v] = max(best[v], sz[to]);
        }
    }
    return 0;
}

const int MAXV = 2e6 + 5;

int tcounter;
pair<int, ll> have[MAXV];
ll ans[MAXN];

ll get_have(int num) {
    if (have[num].ff == tcounter) {
        return have[num].ss;
    }
    return 0;
}

void plus_have(int num, int val) {
    if (have[num].ff != tcounter) {
        have[num] = {tcounter, 0};
    }
    have[num].ss += val;
}


vector<int> all_masks;

ll dfs(int v, int p, int mask) {
    mask ^= (1 << (lets[v] - 'a'));
    all_masks.puba(mask);
    ll ret = 0;
    for (int i = 0; i < 20; ++i) {
        ret += get_have(mask ^ (1 << i));
    }
    ret += get_have(mask);
    for (int to : graph[v]) {
        if (!used[to] && to != p) {
            ret += dfs(to, v, mask);
        }
    }
    ans[v] += ret;
    return ret;
}

int rec(int v) {
    visited.clear();
    calc_sz(v, v);
    int val = INF;
    for (int u : visited) {
        best[u] = max(best[u], szof(visited) - 1 - sz[u]);
        if (val > best[u]) {
            val = best[u];
            v = u;
        }
    }


    //cerr << "root is " << v + 1 << endl;
    used[v] = 1;

    ++tcounter;

    int rmask = 1 << (lets[v] - 'a');
    plus_have(rmask, 1);

    for (int to : graph[v]) {
        if (!used[to]) {
            all_masks.clear();
            ll tmp = dfs(to, v, 0);
            ans[v] += tmp;
            for (int num : all_masks) {
                plus_have(num ^ rmask, 1);
            }
        }
    }

    ++tcounter;
    //plus_have(rmask, 1);

    for (int i = szof(graph[v]) - 1; i >= 0; --i) {
        int to = graph[v][i];
        if (!used[to]) {
            all_masks.clear();
            dfs(to, v, 0);
            for (int num : all_masks) {
                plus_have(num ^ rmask, 1);
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cerr << ans[i] << " ";
    }
    cerr << endl;
    */
    for (int to : graph[v]) {
        if (!used[to]) {
            rec(to);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    cin >> lets;
    
    rec(0);
    
    for (int i = 0; i < n; ++i) {
        ans[i]++;
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}