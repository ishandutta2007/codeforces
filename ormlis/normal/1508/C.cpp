#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 100;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct dsu {
    vector<int> dsu;
    vector<int> rank;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k + 10;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
        rank.resize(n, 1);
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (a == b) return false;
        if (rank[a] > rank[b]) swap(a, b);
        dsu[a] = b;
        rank[b] += rank[a];
        return true;
    }
} D;

vector<int> g[maxN];
vector<pair<int, bool>> gg[maxN];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 3>> edges(m);
    ll ost = (1ll * n * n - n) / 2 - m;
    int need = 0;
    range(i, m) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        need ^= edges[i][0];
        g[edges[i][1]].push_back(edges[i][2]);
        g[edges[i][2]].push_back(edges[i][1]);
    }
    D.build(n);
    set<int> has;
    for (int i = 1; i <= n; ++i) {
        map<int, int> cnt;
        set<int> bad;
        for (auto u : g[i]) {
            u = D.get_dsu(u);
            if (!has.count(u)) continue;
            cnt[u]++;
            if (D.rank[u] == cnt[u]) bad.insert(u);
        }
        vector<int> dels;
        for (auto &w : has) {
            if (bad.count(w)) continue;
            D.unio(w, i);
            dels.push_back(w);
        }
        for (auto &w : dels) has.erase(w);
        has.insert(D.get_dsu(i));
    }
    sort(all(edges));
    vector<bool> us(m);
    ll kek = n - (int) has.size();
    auto G = D;
    if (kek < ost) need = 0;
    ll res = 0;
    range(i, m) {
        if (G.unio(edges[i][1], edges[i][2])) {
            res += edges[i][0];
            us[i] = true;
        }
    }
    if (need == 0) {
        cout << res << '\n';
        return;
    }
    dsu DD;
    DD.build(n);
    for(int i = 1; i <= n; ++i) {
        vector<bool> has(n + 1);
        for(auto &u : g[i]) has[u] = true;
        for(int j = 1; j <= n; ++j) {
            if (j == i || has[j]) continue;
            if (DD.unio(i, j)) {
                gg[i].push_back({j, true});
                gg[j].push_back({i, true});
            }
        }
    }
    ll res2 = 0;
    ll mn = INF;
    vector<bool> used(m);
    dsu DD2;
    DD2.build(n);
    range(i, m) {
        if (DD.unio(edges[i][1], edges[i][2])) {
            res2 += edges[i][0];
            gg[edges[i][1]].push_back({edges[i][2], false});
            gg[edges[i][2]].push_back({edges[i][1], false});
            used[i] = true;
            DD2.unio(edges[i][1], edges[i][2]);
            continue;
        }
        if (mn != INF) continue;
        if (DD2.get_dsu(edges[i][1]) == DD2.get_dsu(edges[i][2])) continue;
        mn = edges[i][0];
    }
    cout << min(res + need, res2 + mn);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(2) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}