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

const ll N = 1 << 19;
vector<int> g[N];
ll sz[N], s[N], ans = 0;
ll n, inf = 1e17;

pair<ll, ll> tr[N * 2];

void rem(int v) {
    if (v >= N * 2 || tr[v].second == -inf)
        return;
    tr[v] = {0, -inf};
    rem(v * 2);
    rem(v * 2 + 1);
}
ll f(pair<ll, ll> pr, ll x) {
    return pr.first * x + pr.second;
}
void add(ll v, ll l, ll r, pair<ll, ll> pr) {
    if (v >= N * 2)
        return;
    ll m = (l + r) / 2;
    if (f(pr, m) > f(tr[v], m))
        swap(pr, tr[v]);
    if (pr.first < tr[v].first)
        add(v * 2, l, (l + r) / 2, pr);
    else
        add(v * 2 + 1, (l + r) / 2, r, pr);
}

ll getmx(ll v, ll l, ll r, ll x) {
    if (v > 2 * N)
        return -inf;
    ll m = (l + r) / 2;
    if (x < m)
        return max(f(tr[v], x), getmx(v * 2, l, (l + r) / 2, x));
    return max(f(tr[v], x), getmx(v * 2 + 1, (l + r) / 2, r, x));
}

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : g[v])
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    s[v] = sz[v] * sz[v];
    for (int u : g[v]) {
        if (u == p)
            continue;
        s[v] = min(s[v], sz[v] * (sz[v] - sz[u]) + s[u]);
        ans = max(ans, getmx(1, 0, N, sz[u]) + n * sz[u] - s[u]);
        add(1, 0, N, {-sz[u], n * sz[u] - s[u]});
    }
    rem(1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if (n == 2) {
        cout << 2;
        return 0;
    }
    int u, v;
    rep(i, n - 1) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, N * 2)
        tr[i] = {0, -inf};
    v = 1;
    while (g[v].size() == 1)
        v++;
    dfs(v, -1);
    cout << ans + n * (n - 1) / 2;
}