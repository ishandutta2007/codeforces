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
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10, MOD = 1e9 + 7;
vector<int> g[N];
vector<int> comp(N);
vector<int> ans(N);
set<int> gr[N];
vector<vector<int>> cmp(N);
vector<bool> used(N);
int anss = 1;

void dfs(int v){
    used[v] = 1;
    for (auto to : cmp[v]){
        ans[to] = anss;
    }
    anss++;
    for (auto to : gr[v]){
        if (!used[to]){
            dfs(to);
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) g[i].pb(i);
    vector<pair<int,int>> u;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        u.pb({a, b});
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<pair<vector<int>, int>> take;
    for (int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end());
        take.pb({g[i], i});
    }
    sort(take.begin(), take.end());
    int now = 0;
    for (int i = 0; i < take.size(); i++){
        if (i > 0 && take[i].first != take[i - 1].first){
            now++;
        }
        comp[take[i].second] = now;
        cmp[now].pb(take[i].second);
    }
    now++;
    for (int i = 0; i < u.size(); i++){
        if (comp[u[i].first] != comp[u[i].second]){
            gr[comp[u[i].first]].insert(comp[u[i].second]);
            gr[comp[u[i].second]].insert(comp[u[i].first]);
        }
    }
    if (now == 1){
        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            cout << 1 << ' ';
        }
        return 0;
    }
    int cnt1 = 0;
    for (int i = 0; i < now; i++){
        cnt1 += gr[i].size() == 1;
        if (gr[i].size() > 2){
            cout << "NO\n";
            return 0;
        }
    }
    if (cnt1 == 2){
        for (int i = 0; i < now; i++){
            if (gr[i].size() == 1){
                dfs(i);
                break;
            }
        }
        for (int i = 0; i < now; i++){
            if (!used[i]) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    }
    else{
        cout << "NO\n";
    }
    return 0;
}