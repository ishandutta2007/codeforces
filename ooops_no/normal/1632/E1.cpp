#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10, INF = 1e18;
vector<int> g[N];
vector<int> par(N);
vector<int> used(N);
vector<int> res(N);

struct st {
    vector<int> t;
    st(int n) {
        t.resize(4 * n);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -1e18;
        if (tl == l && tr == r) return t[v];
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

pair<int,int> mx{-1, -1};

void dfs(int v, int p, int d) {
    mx = max(mx, make_pair(d, v));
    for (auto to : g[v]) {
        if (to != p) {
            par[to] = v;
            dfs(to, v, d + 1);
        }
    }
}

void zhfs(int v, int p, int d) {
    res[v] = d;
    for (auto to : g[v]) {
        if (to != p) {
            zhfs(to, v, d + 1);
            if (!used[to]) res[v] = max(res[v], res[to]);
        }
    }
}

vector<int> solve(int n, vector<pair<int,int>> u) {
    mx = {-1, -1};
    for (int i = 0; i < n; i++) {
        g[i].clear();
        used[i] = 0;
        res[i] = 0;
    }
    for (auto to : u) {
        g[to.first].pb(to.second);
        g[to.second].pb(to.first);
    }
    dfs(0, -1, 0);
    int v = mx.second;
    vector<int> arr;
    while (1) {
        arr.pb(v);
        used[v] = 1;
        if (v == 0) break;
        v = par[v];
    }
    zhfs(0, -1, 0);
    int now = 1, need = (int)(arr.size()) - 1;
    vector<int> mx(need + 2);
    mx.back() = -1;
    for (int i = need; i >= 0; i--) {
        mx[i] = max(mx[i + 1], res[arr[i]]);
    }
    st t(n);
    for (int i = 0; i < arr.size(); i++) {
        t.update(1, 0, n - 1, i, res[arr[i]] - 2 * (need - i));
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        while (now < i) now++;
        if (now >= need) {
            ans.pb(need);
            continue;
        }
        while (now < arr.size()) {
            int v = arr[now - i];
            int d = (need) - (now - i), cnt = i;
            int time = (d - i) / 2;
            int ans = max(mx[now - i + time + 1], t.get(1, 0, n - 1, now - i, now - i + time) + d + cnt);
            if (ans <= now) {
                break;
            } else {
                now++;
            }
        }
        ans.pb(now);
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> u(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> u[i].first >> u[i].second;
            u[i].first--, u[i].second--;
        }
        vector<int> ans = solve(n, u);
        for (auto to : ans) {
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}