#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 41;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
map<int, int> color;
int d[maxN];

auto cmp = [](int a, int b) { return d[a] < d[b]; };

int go(int v, int col) {
    if (color.count(v)) return color[v] != col ? 0 : 1;
    color[v] = col;
    int res = 1;
    for (auto u: g[v]) res *= go(u, (col + 1) % 2);
    return res;
}

map<set<int, decltype(cmp)>, ll> mem;

ll count_sp(set<int, decltype(cmp)> &comp) {
    if (comp.empty()) return 1;
    if (mem.count(comp)) return mem[comp];
    int v = *comp.begin();
    comp.erase(comp.begin());
    ll res = count_sp(comp);
    vector<int> deleted = {v};
    for (auto &u: g[v]) {
        if (comp.count(u)) {
            comp.erase(u);
            deleted.push_back(u);
        }
    }
    res += count_sp(comp);
    for (auto &u: deleted) comp.insert(u);
    return mem[comp] = res;
}

int comp[maxN];
set<int> incomp[maxN];

void dfs(int v, int c) {
    comp[v] = c;
    for (auto &u: g[v]) if (!comp[u]) dfs(u, c);
}

void solve() {
    int n, m;
    cin >> n >> m;
    range(_, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> w;
    range(i, n) w.push_back(i + 1);
    shuffle(all(w), mt19937(21525));
    range(i, n) d[w[i]] = i;
    for (int i = 1; i <= n; ++i) {
        if (!comp[i]) {
            dfs(i, i);
        }
        incomp[comp[i]].insert(i);
    }
    ll res[8];

    res[7] = 1ll << n;

    res[0] = m == 0 ? res[7] : 0;

    ll ones = 0;
    for (int i = 1; i <= n; ++i) if (incomp[i].size() == 1) ones++;
    res[1] = res[4] = 1ll << ones;

    res[2] = 1;
    for (int i = 1; i <= n; ++i) if (!incomp[i].empty()) res[2] *= go(*incomp[i].begin(), 0) * 2;

    res[3] = 1;
    for (int i = 1; i <= n; ++i) {
        set<int, decltype(cmp)> s(cmp);
        for (auto &x: incomp[i]) s.insert(x);
        res[3] *= count_sp(s);
        mem.clear();

    }
    res[6] = res[3];

    res[5] = 1;
    for (int i = 1; i <= n; ++i) if (!incomp[i].empty()) res[5] *= 2;

    cout << res[7] + res[1] + res[2] + res[4] - res[0] - res[3] - res[5] - res[6];
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