#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

struct condensation {
    vector<int> ts{};
    vector<vector<pair<int, ll>>> g{}, g2{};
    vector<int> used{};
    vector<vector<int>> comp{};
    vector<int> color{};
    vector<ll> cost{};
    vector<map<int, ll>> gres{};
    int n = 0;
    int cc = 0;

    void dfs1(int v) {
        used[v] = 1;
        for (auto &u: g[v]) if (!used[u.first]) dfs1(u.first);
        ts.push_back(v);
    }

    void dfs2(int v) {
        used[v] = 1;
        comp[cc].push_back(v);
        color[v] = cc;
        for (auto &u: g2[v]) if (!used[u.first]) dfs2(u.first);
    }

    void build(vector<vector<pair<int, ll>>> &init_g) {
        g = init_g;
        n = g.size();
        g2.resize(n);
        range(i, n) for(auto &p: g[i]) g2[p.first].emplace_back(i, p.second);
        used.resize(n);
        range(i, n) if (!used[i]) dfs1(i);
        reverse(all(ts));
        color.resize(n);
        used.assign(n, 0);
        range(i, n) {
            if (!used[ts[i]]) {
                comp.emplace_back();
                dfs2(ts[i]);
                cc++;
            }
        }

        //for cost
        vector<ll> change;
        vector<ll> prefsum;
        ll s = 0;
        for(int i = 0; s <= (ll)1e8; ++i) {
            s += i;
            change.push_back(s);
            if (!prefsum.empty()) prefsum.push_back(s+prefsum.back());
            else prefsum.push_back(s);
        }
        // check this to work right

        gres.resize(cc);
        cost.resize(cc);
        range(i, cc) {
            for(auto &v: comp[i]) {
                for(auto &u: g[v]) {
                    if (color[u.first] != i) gres[i][color[u.first]] = max(gres[i][color[u.first]], u.second);
                    else {
                        int j = lower_bound(all(change), u.second) - change.begin();
                        j--;
                        if (j >= 0) {
                            cost[i] += u.second * (j+1) - prefsum[j];
                        }
                    }
                }
            }
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    range(i, m) {
        int x, y, w; cin >> x >> y >> w;
        x--; y--;
        g[x].emplace_back(y, w);
    }
    condensation co;
    co.build(g);
    int s; cin >> s; s--;
    s = co.color[s];
    n = co.gres.size();
    vector<int> degs(n);
    vector<vector<int>> grev(n);
    range(i, n) {
        degs[i] = co.gres[i].size();
        for(auto &u: co.gres[i]) {
            grev[u.first].push_back(i);
        }
    }
    set<pair<int, int>> sw;
    range(i, n) sw.insert({degs[i], i});
    vector<ll> ans(n);

    while(!sw.empty()) {
        int u = sw.begin()->second;
        sw.erase(sw.begin());
        for(auto &v: co.gres[u]) ans[u] = max(ans[u], ans[v.first] + v.second);
        ans[u] += co.cost[u];
        if (u == s) break;
        for(auto &v: grev[u]) {
            sw.erase({degs[v], v});
            degs[v]--;
            sw.insert({degs[v], v});
        }
    }
    cout << ans[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}