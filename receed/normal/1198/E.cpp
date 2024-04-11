#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

struct e {
    ll u, c, f, rev;
};

const int N = 211;
ll inf = 1e9;
vector<e> g[N];
int used[N], aa[N][N];

void add_edge(int u, int v, ll c) {
    g[u].push_back({v, c, 0, g[v].size()});
    g[v].push_back({u, 0, 0, (int) g[u].size() - 1});
}

ll dfs(int v, ll cf, ll mf, int t) {
    if (v == t)
        return cf;
    used[v] = 1;
    rep(i, g[v].size()) {
        e ce = g[v][i];
        if (!used[ce.u] && ce.f + mf <= ce.c) {
            ll nf = dfs(ce.u, min(cf, ce.c - ce.f), mf, t);
            if (nf) {
                g[v][i].f += nf;
                g[ce.u][ce.rev].f -= nf;
                return nf;
            }
        }
    }
    return 0;
}

ll flow(int s, int t) {
    ll ans = 0, cf;
    for (int i = 30; i >= 0; i--) {
        while (1) {
            memset(used, 0, N * sizeof(int));
            cf = dfs(s, inf, 1 << i, t);
            if (!cf)
                break;
            ans += cf;
        }
    }
    return ans;
}

int lb(ll x, vector<ll> &lx) {
    return lower_bound(all(lx), x) - lx.begin();
}
            

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
    cin >> n >> m;
    vector<ll> lx, ly;
    vector<ll> ax(m), ay(m), bx(m), by(m);
    rep(i, m) {
        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
        bx[i]++; by[i]++;
        lx.push_back(ax[i]);
        lx.push_back(bx[i]);
        ly.push_back(ay[i]);
        ly.push_back(by[i]);
    }
    sort(all(lx));
    lx.resize(unique(all(lx)) - lx.begin());
    sort(all(ly));
    ly.resize(unique(all(ly)) - ly.begin());
    rep(i, m) {
        ax[i] = lb(ax[i], lx);
        ay[i] = lb(ay[i], ly);
        bx[i] = lb(bx[i], lx);
        by[i] = lb(by[i], ly);
        for (int j = ax[i]; j < bx[i]; j++)
            for (int k = ay[i]; k < by[i]; k++)
                aa[j][k] = 1;
    }
    int s = lx.size() + ly.size(), t = s + 1;
    rep(i, (int) lx.size() - 1)
        add_edge(s, i, lx[i + 1] - lx[i]);
    rep(i, (int) ly.size() - 1)
        add_edge(lx.size() + i, t, ly[i + 1] - ly[i]);
    rep(i, lx.size())
        rep(j, ly.size())
            if (aa[i][j]) {
                add_edge(i, lx.size() + j, inf);
            }
    cout << flow(s, t);
}