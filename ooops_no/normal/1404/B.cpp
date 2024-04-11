#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>

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
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int ans = 0;
vector<int> d(N), g[N], used(N);

void dfs(int v){
    d[v] = 1;
    vector<int> a;
    for (auto to : g[v]){
        if (d[to] == 0){
            dfs(to);
            a.pb(d[to]);
            d[v] = max(d[to] + 1, d[v]);
        }
    }
    ans = max(ans, d[v] - 1);
    sort(a.rbegin(), a.rend());
    if (a.size() > 1){
        ans = max(ans, a[0] + a[1]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++){
            g[i].clear();
            used[i] = 0;
            d[i] = 0;
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        ans = 0;
        dfs(1);
        if (db > 2 * da){
            if (ans <= 2 * da){
                cout << "Alice" << endl;
            }
            else{
                deque<pair<int,int>> q;
                vector<int> dd(n + 1);
                q.pb({0, a});
                while(!q.empty()){
                    used[q.front().second] = 1;
                    int v = q.front().second;
                    dd[v] = q.front().first;
                    for (auto to : g[v]){
                        if (!used[to]){
                            used[to] = 1;
                            q.pb({q.front().first + 1, to});
                        }
                    }
                    q.pop_front();
                }
                if (dd[b] <= da){
                    cout << "Alice" << endl;
                }
                else{
                    cout << "Bob" << endl;
                }
            }
        }
        else{
            cout << "Alice" << endl;
        }
    }
    return 0;
}