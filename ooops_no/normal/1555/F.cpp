#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10;
int par[N], sum[N], t[N], tin[N], tout[N], d[N], xr[N], po[20][N], cnt = 0;
vector<pair<int,int>> g[N];
vector<bool> used(N);

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a == b) return 0;
    else{
        if (sum[a] < sum[b]){
            swap(a, b);
        }
        sum[a] += sum[b];
        par[b] = a;
        return 1;
    }
}

struct edge{
    int a, b, c, i;
};

void dfs(int v, int now){
    used[v] = 1;
    tin[v] = cnt++;
    for (int i = 1; i < 20; i++){
        po[i][v] = po[i - 1][po[i - 1][v]];
    }
    xr[v] = now;
    for (auto to : g[v]){
        if (!used[to.first]){
            po[0][to.first] = v;
            d[to.first] = d[v] + 1;
            dfs(to.first, now ^ to.second);
        }
    }
    tout[v] = cnt;
}

int lca(int a, int b){
    if (d[a] < d[b]) swap(a, b);
    for (int i = 19; i >= 0; i--){
        if (d[po[i][a]] >= d[b]){
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--){
        if (po[i][a] != po[i][b]){
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

bool check(int a, int b){
    return (d[b] - d[a] == get(tin[b]) - get(tin[a]));
}

void fill(int a, int b){
    while(a != b){
        inc(tin[a], -1);
        inc(tout[a], 1);
        a = po[0][a];
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) par[i] = i;
    int n, q;
    cin >> n >> q;
    vector<int> ans(q);
    vector<edge> a(q);
    for (int i = 0; i < q; i++){
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].a--, a[i].b--;
        a[i].i = i;
    }
    for (auto to : a){
        if (union_set(to.a, to.b)){
            g[to.a].pb({to.b, to.c});
            g[to.b].pb({to.a, to.c});
            ans[to.i] = 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (!used[i]){
            po[0][i] = i;
            dfs(i, 0);
        }
        inc(tin[i], 1);
        inc(tout[i], -1);
    }
    for (auto to : a){
        if (ans[to.i]) continue;
        if ((xr[to.a] ^ xr[to.b] ^ to.c) != 1) continue;
        int g = lca(to.a, to.b);
        if (!check(to.a, g) || !check(to.b, g)){
            continue;
        }
        ans[to.i] = 1;
        fill(to.a, g), fill(to.b, g);
    }
    for (auto to : ans){
        cout << (to ? "YES\n" : "NO\n");
    }
    return 0;
}