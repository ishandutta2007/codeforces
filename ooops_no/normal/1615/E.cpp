#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int tin[N], tout[N], cnt = 0, d[N], par[N], add[4 * N];
bool used[N];
vector<int> g[N];
pair<int,int> t[4 * N];

void dfs(int v, int p){
    tin[v] = cnt++;
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            par[to] = v;
            dfs(to, v);
        }
    }
    tout[v] = cnt - 1;
}

void push(int v){
    t[v].first += add[v];
    if (v * 2 < 4 * N){
        add[v * 2] += add[v];
        add[v * 2 + 1] += add[v];
    }
    add[v] = 0;
}

void update_pos(int v, int l, int r, int pos, pair<int,int> p){
    push(v);
    if (l == r){
        t[v] = p;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update_pos(2 * v, l, m, pos, p);
    else update_pos(2 * v + 1, m + 1, r, pos, p);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] -= 1;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm)), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return {-1, -1};
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++){
        update_pos(1, 0, n - 1, tin[i], make_pair(d[i], i));
    }
    int have = 0;
    for (int i = 0; i < k; i++){
        int v = get(1, 0, n - 1, 0, n - 1).second;
        if (used[v]) break;
        have++;
        update_pos(1, 0, n - 1, tin[v], {-1, -1});
        while(!used[v]){
            update(1, 0, n - 1, tin[v], tout[v]);
            used[v] = 1;
            if (v == 0) break;
            v = par[v];
        }
    }
    int cnt = 0, ans = 1e18;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            cnt++;
        }
    }
    if (have < k){
        int mx = -1e18;
        for (int j = have; j <= k; j++){
            mx = max(mx, j * (n - j));
        }
        cout << mx << endl;
        return 0;
    }
    for (int i = 0; i <= cnt; i++){
        ans = min(ans, (n - i - have) * (have - i));
    }
    cout << ans << endl;
    return 0;
}