#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e5 * 2;
ll md = 1000000007;

vector<pair<int, ll>> g[maxN];

bool comp(pair<int, ll> &a, pair<int, ll> &b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    set<pair<ll, pair<int, int>>> q;
    vector<map<int, ll>> g2(n + 1);
    range(i, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; ++i) {
        sort(all(g[i]), comp);
        while(g[i].size() > k) g[i].pop_back();
        q.insert({-1, {i, i}});
        g2[i][i] = 0;
    }
    k *= 2;
    k += n - 1;
    ll maxw = 1e9 * 400;
    while(k) {
        int u = q.begin()->second.first;
        int v = q.begin()->second.second;
        ll w = q.begin()->first;
        q.erase(q.begin());
        w = max(w, 0ll);
        k -= 1;
        for(auto x: g[v]) {
            if (g2[u].find(x.first) == g2[u].end() || g2[u][x.first] > w + x.second) {
                if (w + x.second > maxw) continue;
                q.erase({g2[u][x.first], {u, x.first}});
                g2[u][x.first] = w + x.second;
                q.insert({w + x.second, {u, x.first}});
            }
        }
    }
    cout << q.begin()->first;
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