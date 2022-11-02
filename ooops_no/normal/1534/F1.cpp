#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 4e5 + 10;
int n, m;

int comp = 0;
vector<int> g[N], gr[N];
vector<bool> used(N);
vector<int> ans;
vector<int> cmp(N);
vector<pair<int,int>> u;
vector<int> gg[N];

void dfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
    ans.pb(v);
}

void dfs2(int v){
    used[v] = 1;
    cmp[v] = comp;
    for (auto to : gr[v]){
        if (!used[to]){
            dfs2(to);
        }
    }
}

void add_edge(int i, int j){
    g[i].pb(j);
    gr[j].pb(i);
    u.pb({i, j});
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    vector<vector<int>> val(n, vector<int>(m));
    vector<set<pair<int,int>>> st(m);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c[i][j];
            if (c[i][j] == '#'){
                st[j].insert({i, cnt});
                val[i][j] = cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == '#'){
                if (i - 1 >= 0 && c[i - 1][j] == '#'){
                    add_edge(val[i][j], val[i - 1][j]);
                }
                if (st[j].upper_bound({i, cnt}) != st[j].end()){
                    add_edge(val[i][j], (*st[j].upper_bound({i, cnt})).second);
                }
                if (j - 1 >= 0 && st[j - 1].lower_bound({i, 0}) != st[j - 1].end()){
                    add_edge(val[i][j], (*st[j - 1].lower_bound({i, 0})).second);
                }
                if (j + 1 < m && st[j + 1].lower_bound({i, 0}) != st[j + 1].end()){
                    add_edge(val[i][j], (*st[j + 1].lower_bound({i, 0})).second);
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++){
        if (!used[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    fill(used.begin(), used.end(), 0);
    for (auto i : ans){
        if (!used[i]){
            dfs2(i);
            comp++;
        }
    }
    for (auto [a, b] : u){
        if (cmp[a] != cmp[b]){
            gg[cmp[b]].pb(cmp[a]);
        }
    }
    int ans = 0;
    for (int i = 0; i < comp; i++){
        if (gg[i].size() == 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}