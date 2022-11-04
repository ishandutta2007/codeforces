#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

auto mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}

auto maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
vector<int> g[N];
bool used[N];

void run() {
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    int cnt = 0;
    int root = 1;
    rep(i, 1, n + 1) {
        if (sz(g[i]) >= 3) {
            cnt++;
            root = i;
        }
    }
    
    if (cnt >= 2) {
        cout << "No\n";
        return;
    }
    
    used[root] = 1;
    vector<pair<int, int>> res;
    for (int u : g[root]) {
        int v = u;
        while (sz(g[v]) > 1) {
            int nxt = -1;
            for (int w : g[v]) {
                if (used[w]) {
                    continue;
                }
                nxt = w;
            }
            assert(nxt != -1);
            used[v] = 1;
            v = nxt;
        }
        res.pb({root, v});
    }
    cout << "Yes\n";
    cout << sz(res) << "\n";
    for (auto &it : res) {
        cout << it.first << " " << it.second << "\n";
    }
}