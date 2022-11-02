#include<bits/stdc++.h>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(49);

const int N = 3010;
vector<int> g[N];
unordered_map<int, pair<int,int>> used[N];
unordered_set<int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> ans(n + 1, 1e9);
    ans[1] = 0;
    for (int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.insert(a * n * n + b * n + c);
    }
    deque<pair<int, pair<int,int>>> st;
    st.pb({0, {1, 0}});
    while(!st.empty()){
        auto u = st.front();
        st.pop_front();
        for (auto to : g[u.second.first]){
            if (v.find(u.second.second * n * n + u.second.first * n + to) == v.end() && used[u.second.first][to].first == 0){
                used[u.second.first][to] = {u.second.second, u.first + 1};
                ans[to] = min(ans[to], u.first + 1);
                st.pb({u.first + 1, {to, u.second.first}});
            }
        }
    }
    if (ans[n] == 1e9) cout << -1 << endl;
    else {
        if (ans[n] == 1){
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            return 0;
        }
        int now = n, kek = ans[n];
        vector<int> lol;
        lol.pb(n);
        for (int i = 1; i <= n; i++){
            if (used[i][n].second == kek){
                now = i;
                lol.pb(i);
                break;
            }
        }
        if (now != 1){
            pair<int,int> p;
            p.first = used[now][n].first, p.second = now;
            lol.pb(p.first);
            while(p.first != 1){
                int val = used[p.first][p.second].first;
                swap(p.first, p.second);
                lol.pb(val);
                p.first = val;
            }
        }
        cout << lol.size() - 1 << endl;
        for (int i = lol.size() - 1; i > -1; i--){
            cout << lol[i] << " ";
        }
    }
    return 0;
}