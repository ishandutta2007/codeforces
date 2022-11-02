#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10, INF = 1e9;
vector<int> g[N];
int a[N], d[N], val[N], tin[N], tout[N], ind[N], out[N], cnt = 0, n, pow_val[2 * N];
int po[20][2 * N];
vector<int> ans;

struct path{
    int ok, l, r;
};

path t[4 * N];

void dfs(int v, int p){
    tin[v] = cnt++;
    ind[v] = ans.size();
    ans.pb(v);
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            dfs(to, v);
            ans.pb(v);
        }
    }
    out[v] = (int)(ans.size()) - 1;
    tout[v] = cnt++;
}

int lca(int a, int b){
    int i = min(ind[a], ind[b]), j = max(ind[a], ind[b]);
    int dd = pow_val[j - i + 1];
    int u = po[dd][i], v = po[dd][j - (1 << dd) + 1];
    return (d[u] < d[v] ? u : v);
}

bool is_parent(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int in(int a, int b, int c){
    int g = lca(a, b);
    if (is_parent(c, a) && d[c] >= d[g]){
        return 1;
    }
    if (is_parent(c, b) && d[c] >= d[g]){
        return 1;
    }
    return 0;
}

bool check(vector<int> v, int a, int b){
    for (auto to : v){
        if (!in(a, b, to)){
            return 0;
        }
    }
    return 1;
}

path merge(path a, path b){
    path c{0, 0, 0};
    if (a.l == INF) return b;
    if (b.l == INF) return a;
    if (!a.ok || !b.ok){
        return c;
    }
    vector<int> v{a.l, a.r, b.l, b.r};
    if (check(v, a.l, b.l)){
        return {1, a.l, b.l};
    }
    if (check(v, a.l, b.r)){
        return {1, a.l, b.r};
    }
    if (check(v, a.r, b.l)){
        return {1, a.r, b.l};
    }
    if (check(v, a.r, b.r)){
        return {1, a.r, b.r};
    }
    if (check(v, a.l, a.r)){
        return {1, a.l, a.r};
    }
    if (check(v, b.l, b.r)){
        return {1, b.l, b.r};
    }
    return c;
}

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = {1, val, val};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

int go(int v, int l, int r, path a){
    if (l == r){
        return l;
    }
    int m = (l + r) / 2;
    path c = merge(a, t[v * 2]);
    if (c.ok){
        return go(2 * v + 1, m + 1, r, c);
    }
    else{
        return go(2 * v, l, m, a);
    }
}

path get(int v, int tl, int tr, int l, int r){
    if (l > r) return {1, INF, INF};
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int j = 0; j < 20; j++){
        if ((1 << j) < 2 * N){
            pow_val[1 << j] = j;
        }
    }
    for (int i = 1; i < 2 * N; i++){
        pow_val[i] = max(pow_val[i], pow_val[i - 1]);
    }
    for (int i = 0; i < 4 * N; i++){
        t[i] = {1, INF, INF};
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        val[a[i]] = i;
    }
    for (int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    dfs(0, -1);
    for (int i = 0; i < ans.size(); i++){
        po[0][i] = ans[i];
    }
    for (int i = 1; i < 20; i++){
        for (int j = 0; j < ans.size(); j++){
            if (j + (1 << (i - 1)) >= ans.size()){
                po[i][j] = po[i - 1][j];
            }
            else{
                int u = po[i - 1][j], v = po[i - 1][j + (1 << (i - 1))];
                po[i][j] = (d[u] < d[v] ? u : v);
            }
        }
    }
    for (int i = 0; i < n; i++){
        update(1, 0, n - 1, i, val[i]);
    }
    int q;
    cin >> q;
    while(q--){
        int tt;
        cin >> tt;
        if (tt == 1){
            int i, j;
            cin >> i >> j;
            i--, j--;
            swap(a[i], a[j]);
            val[a[i]] = i, val[a[j]] = j;
            update(1, 0, n - 1, a[i], val[a[i]]);
            update(1, 0, n - 1, a[j], val[a[j]]);
        }
        else{
            if (t[1].ok) cout << n << '\n';
            else cout << go(1, 0, n - 1, {1, INF, INF}) << '\n';
        }
    }
    return 0;
}