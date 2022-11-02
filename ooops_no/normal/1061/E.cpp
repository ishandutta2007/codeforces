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
#define int long long
#define ll long long

mt19937 rnd(51);

struct edge{
    int c, cost, f;
};

int n, x, y;
const int N = 2000;
vector<pair<int,int>> g[N];
vector<int> g1[N], g2[N];
vector<edge> e;
vector<int> a(N);
vector<int> need1(N), need2(N);
vector<int> col1(N), col2(N);
vector<int> sum1(N), sum2(N);
vector<int> ans1(N), ans2(N);

void add_edge(int a, int b, int cost, int c){
    g[a].pb({b, e.size()});
    e.pb({c, cost, 0});
    g[b].pb({a, e.size()});
    e.pb({0, -cost, 0});
}

void dfs1(int v, int p, int need){
    if (need1[v] != 0){
        need = v;
    }
    col1[v] = need;
    for (auto to : g1[v]){
        if (to != p){
            dfs1(to, v, need);
            sum1[v] += sum1[to];
        }
    }
    if (sum1[v] > need1[v] && need1[v]){
        cout << -1;
        exit(0);
    }
    ans1[v] = need1[v] - sum1[v];
    sum1[v] = max(sum1[v], need1[v]);
}

void dfs2(int v, int p, int need){
    if (need2[v] != 0){
        need = v;
    }
    col2[v] = need;
    for (auto to : g2[v]){
        if (to != p){
            dfs2(to, v, need);
            sum2[v] += sum2[to];
        }
    }
    if (sum2[v] > need2[v] && need2[v]){
        cout << -1;
        exit(0);
    }
    ans2[v] = need2[v] - sum2[v];
    sum2[v] = max(sum2[v], need2[v]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    x--, y--;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g2[a].pb(b);
        g2[b].pb(a);
    }
    int q, sum = 0;
    cin >> q;
    while(q--){
        int k, x;
        cin >> k >> x;
        k--;
        need1[k] = x;
    }
    cin >> q;
    while(q--){
        int k, x;
        cin >> k >> x;
        k--;
        need2[k] = x;
    }
    dfs1(x, -1, x);
    dfs2(y, -1, y);
    if (need1[x] != need2[y]){
        cout << -1;
        return 0;
    }
    int s = 2 * n, t = 2 * n + 1;
    for (int i = 0; i < n; i++){
        if (need1[i] != 0){
            add_edge(s, i, 0, ans1[i]);
        }
        else{
            add_edge(s, i, 0, 1e9);
        }
        if (need2[i] != 0){
            add_edge(n + i, t, 0, ans2[i]);
        }
        else{
            add_edge(n + i, t, 0, 1e9);
        }
        add_edge(col1[i], col2[i] + n, -a[i], 1);
    }
    int m = t + 1, ans = 0, anss = 0;
    vector<int> pt(m);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            for (auto to : g[j]){
                if (e[to.second].f < e[to.second].c){
                    pt[to.first] = min(pt[to.first], pt[j] + e[to.second].cost);
                }
            }
        }
    }
    while(1){
        vector<int> d(m, 1e18);
        vector<pair<int,int>> par(m, {-1, -1});
        d[s] = 0;
        set<pair<int,int>> st{{0, s}};
        while(st.size() > 0){
            int v = st.begin()->second;
            st.erase(st.begin());
            for (auto to : g[v]){
                if (e[to.second].f < e[to.second].c && d[to.first] > pt[v] - pt[to.first] + e[to.second].cost + d[v]){
                    assert(pt[v] - pt[to.first] + e[to.second].cost >= 0);
                    st.erase({d[to.first], to.first});
                    d[to.first] = pt[v] - pt[to.first] + e[to.second].cost + d[v];
                    par[to.first] = {v, to.second};
                    st.insert({d[to.first], to.first});
                }
            }
        }
        if (par[t].first == -1){
            break;
        }
        int now = t, mn = 1e18;
        while(now != s){
            mn = min(mn, e[par[now].second].c - e[par[now].second].f);
            now = par[now].first;
        }
        now = t;
        while(now != s){
            int i = par[now].second;
            e[i].f += mn;
            e[i ^ 1].f -= mn;
            ans += e[i].cost * mn;
            now = par[now].first;
        }
        anss += mn;
        int val = pt[s];
        for (int i = 0; i < m; i++) pt[i] = d[i] - val + pt[i];
    }
    cout << (anss != need1[x] ? -1 : -ans) << endl;
    return 0;
}