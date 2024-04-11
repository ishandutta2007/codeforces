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


int n;

bool check(vector<int> v){
    for (int i = 0; i < n; i++){
        if (v[i] != i){
            return 1;
        }
    }
    return 0;
}

int need(vector<int> v){
    vector<bool> used(n + 1);
    for (auto to : v){
        used[to] = 1;
    }
    for (int i = 0; i <= n; i++){
        if (!used[i]){
            return i;
        }
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
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> ans;
        while(check(v)){
            int vv = need(v);
            if (vv == n){
                for (int i = 0; i < n; i++){
                    if (v[i] != i){
                        v[i] = vv;
                        ans.pb(i + 1);
                        break;
                    }
                }
            }
            else{
                v[vv] = vv;
                ans.pb(vv + 1);
            }
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to << " ";
        }
        cout << endl;
    }
    return 0;
}