#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) forn(i, a, (b) + 1)
#define NFOR(i, a, b) for (int i = a; i >= b; --i)

#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())

#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

#define foreach(c, it) for (auto it = (c).begin(); it != (c).end(); ++it)

template <class S, class T>
ostream& operator <<(ostream& os, const pair<S, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class T>
void debug(T a, T b) {
    cerr << "[";
    for (T i = a; i != b; ++i) {
        if (i != a) cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}

const int N = 5050;


struct Store {
    int city, count, price;

    inline bool operator <(const Store& o) const {
        return price < o.price;
    }
} store[N];

vi g[N];
int dis[N][N];

const int INF = 1e9;

void bfs(int src, int n) {
    fill(dis[src], dis[src] + n, INF);
    dis[src][src] = 0;
    queue <int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dis[src][v] == INF) {
                dis[src][v] = dis[src][u] + 1;
                q.push(v);
            }
        }
    }
}

int n, m, w;

const ll INFL = 1e18;

ll getCost(int id, int need, int allowed) {
    ll cost = 0;
    rep (i, w) {
        if (dis[store[i].city][id] <= allowed) {
            if (need <= store[i].count) {
                cost += 1ll * need * store[i].price;
                need = 0;
                break;
            } else {
                cost += 1ll * store[i].count * store[i].price;
                need -= store[i].count;
            }
        }
    }
    return need == 0 ? cost : INFL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    rep (i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    cin >> w;
    rep (i, w) {
        cin >> store[i].city >> store[i].count >> store[i].price;
        --store[i].city;
    }
    sort(store, store + w);

    rep (i, w) {
        bfs(store[i].city, n);
    }

    int q;
    cin >> q;

    while (q--) {
        int city, need, have;
        cin >> city >> need >> have;
        --city;

        int l = 0, r = 1e5;
        while (l < r) {
            int mid = (l + r) >> 1;
            ll cost = getCost(city, need, mid);
            if (cost > have) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (getCost(city, need, l) <= have) {
            cout << l << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}