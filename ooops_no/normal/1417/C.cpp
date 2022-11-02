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
        int n;
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> a(n + 1);
        vector<int> ans(n, 1e18);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            a[v[i]].pb(i);
        }
        for (int i = 1; i <= n; i++){
            if (a[i].size() == 0){
                continue;
            }
            int mx = 0;
            for (int j = 0; j + 1 < a[i].size(); j++){
                mx = max(mx, a[i][j + 1] - a[i][j]);
            }
            mx = max(mx, a[i][0] + 1);
            mx = max(mx, n - a[i][a[i].size() - 1]);
            ans[mx - 1] = min(ans[mx - 1], i);
        }
        int rm = -1;
        for (int i = 0; i < n; i++){
            if (ans[i] != 1e18){
                if (rm == -1) rm = ans[i];
                else rm = min(rm, ans[i]);
            }
            cout << rm << " ";
        }
        cout << endl;
    }
    return 0;
}