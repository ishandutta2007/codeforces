#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 5e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<pair<int, int>> g[maxN];

vector<int> cycle;
int used[maxN];
void dfs(int v, int p, int f) {
    if (p != -1 && f == v) {
        return;
    }
    used[v] = 1;
    cycle.push_back(v);
    for(auto &w: g[v]) {
        if (w.first == p) continue;
        dfs(w.first, v, f);
        break;
    }
}

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        range(i, 2 * n) cout << i % n + 1 << " ";
        cout << endl;
        return;
    }
    cout << "Second" << endl;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) {
        int x1; cin >> x1;
        x1--;
        g[a[i]-1].emplace_back(x1, i + 1);
        g[x1].emplace_back(a[i]-1, i + n + 1);
        if (a[i] - 1 != x1 && g[x1][0].first == a[i]-1 && g[x1][0].second != i + n + 1) swap(g[x1][0], g[x1][1]);
    }
    vector<vector<int>> cycles;
    int k = -1;
    range(i, n) {
        if (used[i]) continue;
        dfs(i, -1, i);
        cycles.push_back(cycle);
        if (cycle.size() % 2) k = i;
        cycle.clear();
    }
    ll ans = 0;
    vector<pair<ll, ll>> vibor;
    vector<pair<vector<int>, vector<int>>> vibor2;
    for(auto &cyc: cycles) {
        vibor.emplace_back(0, 0);
        vibor2.push_back({{}, {}});
        range(i, (int)cyc.size()) {
            int v = cyc[i];
            int u = cyc[(i+1) % (int)cyc.size()];
            for(int j = 0; j < (int)g[v].size(); ++j) {
                if (g[v][j].first == u) {
                    vibor.back().first += g[v][j].second;
                    vibor2.back().first.push_back(g[v][j].second);
                    break;
                }
            }
            for(int j = (int)g[u].size() - 1; j >= 0; --j) {
                if (g[u][j].first == v) {
                    vibor.back().second += g[u][j].second;
                    vibor2.back().second.push_back(g[u][j].second);
                    break;
                }
            }
        }
        ans += vibor.back().first;
    }
    if (ans % (1ll * 2 * n) == 0) {
        for(auto &p: vibor2) {
            for(auto &x: p.first) cout << x << " ";
        }
        cout << endl;
    } else {
        bool fand = false;
        for(auto &p: vibor2) {
            if (p.first.size() % 2 && !fand) {
                for(auto &x: p.second) cout << x << " ";
                fand = true;
            } else {
                for (auto &x: p.first) cout << x << " ";
            }
        }
        cout << endl;
     }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}