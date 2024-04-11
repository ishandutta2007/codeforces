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

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> u(m);
    vector<set<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
        g[u[i].first].insert(u[i].second);
        g[u[i].second].insert(u[i].first);
        deg[u[i].first]++;
        deg[u[i].second]++;
    }
    reverse(u.begin(), u.end());
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++){
        st.insert({deg[i], i});
    }
    vector<int> ans;
    for (auto [x, y] : u){
        while(st.size() > 0 && st.begin()->first < k){
            pair<int,int> p = *st.begin();
            for (auto to : g[p.second]){
                st.erase({deg[to], to});
                g[to].erase(p.second);
                deg[to]--;
                st.insert({deg[to], to});
            }
            g[p.second].clear();
            st.erase(p);
        }
        ans.pb(st.size());
        if (g[x].find(y) != g[x].end()){
            st.erase({deg[x], x});
            st.erase({deg[y], y});
            g[x].erase(y);
            g[y].erase(x);
            deg[y]--;
            deg[x]--;
            st.insert({deg[x], x});
            st.insert({deg[y], y});
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto to : ans){
        cout << to << endl;
    }
    return 0;
}