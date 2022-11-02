#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int INF = 1e9, N = 1e6 + 10;
vector<int> g[N], gr[N], up[N], a(N), d(N), sum0(N), sum1(N), mn(N);
vector<bool> used(N);
int cnt0 = 0, cnt1 = 0;
string ans = "";
int n, m;

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            gr[v].pb(to);
            d[to] = d[v] + 1;
            dfs(to);
        }
    }
}

void zhfs(int v, int d) {
    a[v] = d;
    for (auto to : gr[v]) {
        zhfs(to, d ^ 1);
    }
}

void get_ans(int v) {
    map<int,int> was;
    deque<int> q{v};
    while (q.size() > 0) {
        int u = q.front();
        was[u] = 1;
        q.pop_front();
        for (auto to : gr[u]) {
            q.pb(to);
        }
    }
    string res = "";
    for (int i = 0; i < n; i++) {
        if (was[i]) {
            res += (a[i] ^ 1) + '0';
        } else {
            res += a[i] + '0';
        }
    }
    ans = res;
}

void check(int v) {
    if (ans.size() > 0) {
        return;
    }
    if (mn[v] >= d[v] && cnt0 == sum0[v] && cnt1 == sum1[v]) {
        get_ans(v);
    }
}

void walk(int v) {
    sum0[v] = sum1[v] = 0;
    mn[v] = INF;
    for (auto to : up[v]) {
        if (a[to] == 0 && a[v] == 0) {
            sum0[v]++;
            sum0[to]--;
        }
        if (a[to] == 1 && a[v] == 1) {
            sum1[v]++;
            sum1[to]--;
        }
        if (a[to] == 0 && a[v] == 1) {
            mn[v] = min(mn[v], d[to]);
        }
        if (a[to] == 1 && a[v] == 0) {
            mn[v] = min(mn[v], d[to]);
        }
    }
    for (auto to : gr[v]) {
        walk(to);
        sum0[v] += sum0[to];
        sum1[v] += sum1[to];
        mn[v] = min(mn[v], mn[to]);
    }
}

void gfs(int v) {
    if (a[v] == 0 && v == 0 && g[v].size() == 1) {
        check(v);
    }
    if (a[v]) {
        for (auto to : gr[v]) {
            check(to);
        }
    }
    for (auto to : gr[v]) {
        gfs(to);
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<pair<int,int>> u(m);
        for (int i = 0; i < n; i++) {
            used[i] = 0;
            g[i].clear();
            gr[i].clear();
            up[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            u[i] = {a, b};
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0);
        for (int i = 0; i < m; i++) {
            int a = u[i].first, b = u[i].second;
            if (abs(d[a] - d[b]) == 1) continue;
            if (d[a] < d[b]) {
                up[b].pb(a);
            } else {
                up[a].pb(b);
            }
        }
        ans = "";
        for (int i = 0; i < 2; i++) {
            cnt0 = cnt1 = 0;
            zhfs(0, i);
            for (auto to : u) {
                if (a[to.first] == 0 && a[to.second] == 0) {
                    cnt0++;
                }
                if (a[to.first] == 1 && a[to.second] == 1) {
                    cnt1++;
                }
            }
            if (cnt0 == 0 && cnt1 <= 1) {
                string t = "";
                for (int j = 0; j < n; j++) {
                    t += a[j] + '0';
                }
                ans = t;
            }
            walk(0);
            gfs(0);
        }
        if (ans.size() == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << ans << "\n";
        }
    }
    return 0;
}