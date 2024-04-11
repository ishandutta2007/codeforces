#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 5e5 + 10;
vector<pair<int,int>> g[N];
vector<int> vert[N], gr[N];
int po[20][N], d[N], sz[N], tin[N], tout[N], cnt = 0, sum[N], type[N], need;
ll ans = 0;

void dfs(int v, int p) {
    sz[v] = 1;
    tin[v] = cnt++;
    for (auto to : g[v]) {
        if (to.first != p) {
            po[0][to.first] = v;
            d[to.first] = d[v] + 1;
            vert[to.second].pb(to.first);
            type[to.first] = to.second;
            dfs(to.first, v);
            sz[v] += sz[to.first];
        }
    }
    tout[v] = cnt++;
}

int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--) {
        if (d[po[i][a]] >= d[b]) {
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (po[i][a] != po[i][b]) {
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

void zhfs(int v) {
    for (auto to : gr[v]) {
        zhfs(to);
        sum[v] += sum[to];
    }
    if (type[v] == need) {
        sum[v] = sz[v];
    }
}

void gfs(int v, int up) {
    if (type[v] == need) {
        int val = sz[v];
        for (auto to : gr[v]) {
            val -= sum[to];
        }
        ans += (ll)up * val;
        up = 0;
    }
    int res = sz[v];
    for (auto to : gr[v]) {
        res -= sum[to];
    }
    for (auto to : gr[v]) {
        gfs(to, up + res + sum[to] - sz[to]);
    }
}

bool is_parent(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs(0, -1);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (vert[i].size() > 0) {
            need = i;
            vector<int> arr = vert[i];
            sort(arr.begin(), arr.end(), [&](int a, int b){return tin[a] < tin[b];});
            int m = arr.size();
            for (int j = 0; j + 1 < m; j++) {
                arr.pb(lca(arr[j], arr[j + 1]));
            }
            sort(arr.begin(), arr.end(), [&](int a, int b){return tout[a] < tout[b];});
            arr.erase(unique(arr.begin(), arr.end()), arr.end());
            deque<int> q;
            for (auto v : arr) {
                gr[v].clear();
                sum[v] = 0;
            }
            for (auto v : arr) {
                while (q.size() > 0 && is_parent(v, q.back())) {
                    gr[v].pb(q.back());
                    q.pop_back();
                }
                q.pb(v);
            }
            int r = q[0];
            zhfs(r);
            gfs(r, n - sz[r]);
        }
    }
    cout << ans << endl;
    return 0;
}