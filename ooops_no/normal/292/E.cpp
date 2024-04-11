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
#include<cassert>
#include <iomanip>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<int, pair<int,int>>, null_type, less<pair<int, pair<int,int>>>, rb_tree_tag, tree_order_statistics_node_update> st;


*/

/*

st.find_by_order();
st.order_of_key();

*/

#define pb push_back
#define ld double

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int kk = sqrt(m);
    vector<int> a(n), b(n);
    vector<vector<pair<pair<int, int>, pair<int,int>>>> v(sqrt(m) + 5);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (t == 1){
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            v[i / kk].pb({{t, x}, {y, k}});
        }
        else{
            int x;
            cin >> x;
            x--;
            v[i / kk].pb({{t, x}, {0, 0}});
        }
    }
    int g, l, r, x, d;
    for (int i = 0; i < v.size(); i++){
        vector<int> u;
        for (auto to : v[i]){
            if (to.first.first == 2){
                u.pb(to.first.second);
            }
        }
        for (auto to : v[i]){
            if (to.first.first == 1){
                l = to.second.first, r = to.second.first + to.second.second - 1, x = to.first.second;
                for (auto t : u){
                    if (l <= t && t <= r){
                        b[t] = a[x + t - l];
                    }
                }
            }
            else{
                cout << b[to.first.second] << endl;
            }
        }
        vector<vector<int>> ans(n);
        for (int j = 0; j < v[i].size(); j++){
            auto to = v[i][j];
            if (to.first.first == 1){
                int l = to.second.first;
                ans[l].pb(j);
            }
        }
        set<int> q;
        for (int j = 0; j < n; j++){
            while(!q.empty()){
                auto it = *q.rbegin();
                if (v[i][it].second.first + v[i][it].second.second - 1 < j){
                    q.erase(it);
                }
                else{
                    break;
                }
            }
            for (auto to : ans[j]){
                q.insert(to);
            }
            if (q.size() == 0) continue;
            else{
                g = *q.rbegin() + 1;
                l = v[i][g - 1].first.second, d = j - v[i][g - 1].second.first;
                b[j] = a[l + d];
            }
        }
    }
    return 0;
}