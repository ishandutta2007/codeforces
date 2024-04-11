#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
vector<int> par(N);
vector<int> sum(N);
vector<pair<int,int>> can[N];
int n, m, x;

int find_set(int v){
    if (par[v] == v) return v;
    else return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (can[a].size() > can[b].size()){
        for (auto to : can[b]){
            can[a].pb(to);
        }
        sum[a] += sum[b] - x;
        par[b] = a;
    }
    else{
        for (auto to : can[a]){
            can[b].pb(to);
        }
        sum[b] += sum[a] - x;
        par[a] = b;
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) par[i] = i;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++){
        cin >> sum[i];
    }
    vector<pair<int,int>> a;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        can[u].pb({v, i});
        can[v].pb({u, i});
        a.pb({u, v});
    }
    vector<int> ans;
    set<pair<int,int>> st;
    for (int i = 1; i <= n; i++){
        st.insert({sum[i], i});
    }
    for (int i = 0; i < n - 1; i++){
        auto v = (*st.rbegin()).second;
        bool xq = 0;
        while(can[v].size() > 0){
            auto to = can[v].back();
            if (find_set(to.first) == find_set(v) || sum[find_set(to.first)] + sum[find_set(v)] < x){
                can[v].pop_back();
            }
            else{
                st.erase({sum[find_set(to.first)], find_set(to.first)});
                st.erase({sum[find_set(v)], find_set(v)});
                union_set(to.first, v);
                st.insert({sum[find_set(v)], find_set(v)});
                xq = 1;
                ans.pb(to.second);
                break;
            }
        }
        if (!xq){
            cout << "NO\n";
            exit(0);
        }
    }
    cout << "YES\n";
    for (auto to : ans){
        cout << to + 1 << endl;
    }
    return 0;
}