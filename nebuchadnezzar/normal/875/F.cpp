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

const int MAXN = 4e5 + 5;

int dsu[MAXN];
int flag[MAXN];

int get_root(int a) {
    return a == dsu[a] ? a : dsu[a] = get_root(dsu[a]);
}

int unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);

    dsu[a] = b;
    flag[b] |= flag[a];
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
    }

    vector<tuple<int, int, int>> inp;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        --a; --b;
        inp.puba({a, b, w});
    }

    sort(bend(inp), [](tuple<int, int, int> a, tuple<int, int, int> b) { return get<2>(a) > get<2>(b); });

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        tie(a, b, w) = inp[i];
        if (get_root(a) != get_root(b) && !(flag[get_root(a)] && flag[get_root(b)])) {
            ans += w;
            unite(a, b);
        } else {
            if (!flag[get_root(a)]) {
                flag[get_root(a)] = true;
                ans += w;
            }
        }
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}