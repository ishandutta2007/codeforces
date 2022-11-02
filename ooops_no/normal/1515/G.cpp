#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const ll INF = 1e18;
const int N = 2e5 + 10;
int cnt = 1;
bool used[N];
vector<ll> d(N, INF);
vector<int> ord, gr[N], mas, comp(N);
vector<pair<int,int>> g[N];
ll gc[N];

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to.first]) {
            dfs(to.first);
        }
    }
    ord.pb(v);
}

void zhfs(int v) {
    comp[v] = cnt;
    mas.pb(v);
    for (auto to : gr[v]) {
        if (comp[to] == 0) {
            zhfs(to);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> arr;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        arr.pb({a, b, l});
        g[a].pb({b, l});
        gr[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
    for (auto v : ord) {
        if (comp[v] == 0) {
            mas.clear();
            zhfs(v);
            cnt++;
            deque<int> q{v};
            d[v] = 0;
            while (q.size() > 0) {
                int u = q.front();
                q.pop_front();
                for (auto to : g[u]) {
                    if (comp[u] == comp[to.first] && d[to.first] == INF) {
                        d[to.first] = d[u] + to.second;
                        q.pb(to.first);
                    }
                }
            }
            for (auto u : mas) {
                for (auto to : g[u]) {
                    if (comp[u] == comp[to.first]) {
                        if (d[to.first] < d[u]) {
                            gc[comp[u]] = gcd(gc[comp[u]], d[u] - d[to.first] + to.second);
                        } else {
                            gc[comp[u]] = gcd(gc[comp[u]], abs(to.second - (d[to.first] - d[u])));
                        }
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, s, t;
        cin >> u >> s >> t;
        u--;
        cout << ((t - s) % gcd(t, gc[comp[u]]) == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}