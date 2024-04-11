#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> g[N], d(N), sz(N), res2(N);
vector<vector<int>> st(N);
ll cnt2 = 0, n, need = -1;

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

int find_centroid(int v, int p) {
    for (auto to : g[v]) {
        if (to != p && sz[to] > n / 2) {
            return find_centroid(to, v);
        }
    }
    return v;
}

void zhfs(int v, int p) {
    if (need != -1) {
        st[need].pb(v);
    }
    for (auto to : g[v]) {
        if (to != p) {
            if (p == -1) need = to;
            d[to] = d[v] + 1;
            zhfs(to, v);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    int u = find_centroid(0, -1);
    zhfs(u, -1);
    for (int i = 0; i < n; i++) cnt2 += d[i] * 2;
    cout << cnt2 << endl;
    set<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        if (st[i].size() > 0) {
            q.insert({-(int)(st[i].size()), i});
        }
    }
    int lasta = -1, lastb = -1;
    while (q.size() > 1) {
        int a = q.begin()->second;
        q.erase(q.begin());
        int b = q.begin()->second;
        q.erase(q.begin());
        res2[st[a].back()] = st[b].back();
        res2[st[b].back()] = st[a].back();
        lasta = st[a].back();
        lastb = st[b].back();
        st[a].pop_back();
        st[b].pop_back();
        if (st[a].size() > 0) q.insert({-(int)(st[a].size()), a});
        if (st[b].size() > 0) q.insert({-(int)(st[b].size()), b});
    }
    if (q.size() == 1) {
        int a = q.begin()->second;
        res2[st[a][0]] = u;
        res2[u] = st[a][0];
    } else {
        assert(lasta != -1 && lastb != -1);
        res2[lasta] = u;
        res2[u] = lastb;
        res2[lastb] = lasta;
    }
    for (int i = 0; i < n; i++) {
        cout << res2[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}