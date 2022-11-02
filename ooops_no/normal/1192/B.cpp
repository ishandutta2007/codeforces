#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1e5 + 10;
int cost[N], sz[N], dl[N];
bool used[N];
vector<int> t[N], add[N];
vector<pair<int,int>> g[N], need[N], change[N];
vector<set<pair<int,int>>> val(N);
vector<unordered_map<int,int>> in(N), out(N);
int needd = 0, cnt =  0;
set<pair<int,int>> best;

void push(int i, int v){
    t[i][v] += add[i][v];
    add[i][v * 2] += add[i][v];
    add[i][v * 2 + 1] += add[i][v];
    add[i][v] = 0;
}

void update(int i, int v, int tl, int tr, int l, int r, int val){
    push(i, v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[i][v] += val;
        push(i, v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(i, 2 * v, tl, tm, l, min(r, tm), val), update(i, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[i][v] = max(t[i][v * 2], t[i][v * 2 + 1]);
}

int get(int i, int v, int tl, int tr, int l, int r){
    push(i, v);
    if (l > r) return -1e18;
    if (tl == l && tr == r){
        return t[i][v];
    }
    int tm = (tl + tr) / 2;
    return max(get(i, 2 * v, tl, tm, l, min(r, tm)), get(i, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void zhfs(int v, int p){
    sz[v] = 1;
    needd++;
    for (auto to : g[v]){
        if (!used[to.first] && to.first != p){
            zhfs(to.first, v);
            sz[v] += sz[to.first];
        }
    }
}

void dfs(int v, int p, int pp, int vv){
    in[vv][v] = cnt++;
    for (auto to : g[v]){
        if (to.first != p && !used[to.first]){
            dfs(to.first, v, pp, vv);
            change[to.second].emplace_back(make_pair(vv, to.first));
            need[to.second].emplace_back(make_pair(vv, pp));
            update(vv, 1, 0, dl[vv] - 1, in[vv][to.first], out[vv][to.first], cost[to.second]);
        }
    }
    out[vv][v] = cnt - 1;
}

int find_centroid(int v, int p, int n){
    for (auto to : g[v]){
        if (to.first != p && !used[to.first] && sz[to.first] > n / 2){
            return find_centroid(to.first, v, n);
        }
    }
    return v;
}

void upd(int v, int f){
    auto it = val[v].rbegin();
    pair<int,int> rm = (*it);
    int sum = (*it).first;
    val[v].erase(*it);
    it = val[v].rbegin();
    sum += (*it).first;
    val[v].insert(rm);
    if (f) {
        best.insert({sum, v});
    }
    else {
        best.erase({sum, v});
    }
}

void solve(int v){
    needd = 0;
    zhfs(v, -1);
    dl[v] = needd - 1;
    t[v].resize(dl[v] * 4);
    add[v].resize(dl[v] * 8);
    val[v].insert({0, 0});
    val[v].insert({0, -1});
    cnt = 0;
    for (auto to : g[v]){
        if (!used[to.first]){
            dfs(to.first, v, to.first, v);
            change[to.second].emplace_back(make_pair(v, to.first));
            need[to.second].emplace_back(make_pair(v, to.first));
            update(v, 1, 0, dl[v] - 1, in[v][to.first], out[v][to.first], cost[to.second]);
            val[v].insert({get(v, 1, 0, dl[v] - 1, in[v][to.first], out[v][to.first]), to.first});
        }
    }
    upd(v, 1);
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to.first]){
            solve(find_centroid(to.first, v, sz[to.first]));
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, w;
    cin >> n >> q >> w;
    for (int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[i] = c;
        g[a].emplace_back(make_pair(b, i));
        g[b].emplace_back(make_pair(a, i));
    }
    zhfs(1, -1);
    solve(find_centroid(1, -1, n));
    int last = 0;
    for (int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        int j = (last + a) % (n - 1), c = (b + last) % w;
        for (auto [v, to] : need[j]){
            upd(v, 0);
            val[v].erase({get(v, 1, 0, dl[v] - 1, in[v][to], out[v][to]), to});
        }
        for (auto [v, to] : change[j]){
            update(v, 1, 0, dl[v] - 1, in[v][to], out[v][to], c - cost[j]);
        }
        for (auto [v, to] : need[j]){
            val[v].insert({get(v, 1, 0, dl[v] - 1, in[v][to], out[v][to]), to});
            upd(v, 1);
        }
        cost[j] = c;
        int ans = 0;
        ans = (*best.rbegin()).first;
        cout << ans << "\n";
        last = ans;
    }
    return 0;
}