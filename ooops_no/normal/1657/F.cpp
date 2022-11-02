#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 4e5 + 10;
int tin[N], tout[N], cntt = 0, par[N], cnt[N][26], sum[N];
vector<int> g[N];

struct TwoSat {
    vector<int> used, ans, comp;
    vector<vector<int>> g, gr;
    int n, cnt = 0;
    TwoSat(int _n) {
        n = _n;
        g.resize(n);
        gr.resize(n);
        used.resize(n);
        comp.resize(n, -1);
    }
    void add(int a, int b) {
        g[a].pb(b);
        gr[b].pb(a);
    }
    void add_or(int a, bool A, int b, bool B) {
        a *= 2, b *= 2;
        a ^= A;
        b ^= B;
        add(a ^ 1, b);
        add(b ^ 1, a);
    }
    void dfs(int v) {
        used[v] = 1;
        for (auto to : g[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
        ans.pb(v);
    }
    void dfs2(int v) {
        comp[v] = cnt;
        for (auto to : gr[v]) {
            if (comp[to] == -1) {
                dfs2(to);
            }
        }
    }
    bool solve() {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto v : ans) {
            if (comp[v] == -1) {
                dfs2(v);
                cnt++;
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) return 0;
        }
        return 1;
    }
};

void dfs(int v, int p) {
    tin[v] = cntt++;
    for (auto to : g[v]) {
        if (to != p) {
            par[to] = v;
            dfs(to, v);
        }
    }
    tout[v] = cntt++;
}

bool is_parent(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    vector<string> s(q);
    vector<vector<int>> arr(q);
    vector<int> need(n, -1);
    vector<vector<char>> ans(n, vector<char>(2, 0));
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v >> s[i];
        u--, v--;
        vector<int> arr2;
        while (!is_parent(u, v)) {
            arr[i].pb(u);
            u = par[u];
        }
        arr[i].pb(u);
        while (v != u) {
            arr2.pb(v);
            v = par[v];
        }
        reverse(arr2.begin(), arr2.end());
        for (auto to : arr2) arr[i].pb(to);
        int sz = arr[i].size();
        for (int j = 0; j < arr[i].size(); j++) {
            int a = arr[i][j];
            sum[a]++;
            cnt[a][s[i][j] - 'a']++;
            if (s[i][j] != s[i][sz - j - 1]) cnt[a][s[i][sz - j - 1] - 'a']++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i] == 0) continue;
        vector<int> all;
        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] == sum[i]) {
                all.pb(j);
            }
        }
        if (all.size() == 0) {
            cout << "NO\n";
            return 0;
        }
        if (all.size() == 1) {
            need[i] = all[0];
            ans[i][0] = ans[i][1] = need[i];
        } else {
            ans[i][0] = all[0];
            ans[i][1] = all[1];
        }
    }
    TwoSat Sat(2 * (n + q));
    for (int i = 0; i < q; i++) {
        int sz = arr[i].size();
        for (int j = 0; j < sz; j++) {
            int a = arr[i][j];
            if (need[a] != -1) {
                if (need[a] == s[i][j] - 'a' && need[a] == s[i][sz - j - 1] - 'a') {
                    continue;
                }
                if (need[a] == s[i][j] - 'a') {
                    Sat.add_or(i, 0, i, 0);
                } else {
                    Sat.add_or(i, 1, i, 1);
                }
            } else {
                if (ans[a][0] == s[i][j] - 'a') {
                    Sat.add_or(i, 0, a + q, 1);
                    Sat.add_or(i, 1, a + q, 0);
                } else {
                    Sat.add_or(i, 0, a + q, 0);
                    Sat.add_or(i, 1, a + q, 1);
                }
            }
        }
    }
    bool f = Sat.solve();
    if (!f) {
        cout << "NO\n";
        return 0;
    }
    int now = 0;
    for (int i = 2 * q; i < 2 * (n + q); i += 2) {
        if (Sat.comp[i] < Sat.comp[i + 1]) {
            swap(ans[now][0], ans[now][1]);
        }
        now++;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        ans[i][0] += 'a';
        cout << ans[i][0];
    }
    cout << endl;
    return 0;
}