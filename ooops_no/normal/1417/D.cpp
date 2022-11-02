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
#define ld double
#define int long long

mt19937 rnd(49);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++){
            cin >> v[i + 1];
            sum += v[i + 1];
        }
        if (sum % n != 0){
            cout << -1 << "\n";
        }
        else{
            vector<pair<int, pair<int,int>>> ans;
            for (int i = 2; i <= n; i++){
                if (v[i] % i != 0){
                    int val = i - v[i] % i;
                    v[i] += val;
                    v[1] -= val;
                    ans.pb({1, {i, val}});
                }
                ans.pb({i, {1, v[i] / i}});
                v[1] += v[i];
                v[i] = 0;
            }
            for (int i = 2; i <= n; i++){
                ans.pb({1, {i, sum / n}});
            }
            cout << ans.size() << "\n";
            for (auto to : ans){
                cout << to.first << " " << to.second.first << " " << to.second.second << "\n";
            }
        }
    }
    return 0;
}