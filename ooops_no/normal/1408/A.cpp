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
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            if (i == 0){
                p[i] = a[i];
            }
            else{
                if (a[i] == p[i - 1]){
                    p[i] = b[i];
                }
                else{
                    p[i] = a[i];
                }
            }
        }
        if (p[n - 1] == p[0]){
            if (c[n - 1] != p[n - 2] && c[n - 1] != p[n - 2]){
                p[n - 1] = c[n - 1];
            }
            else if (b[n - 1] != p[n - 2] && p[n - 2] != b[n - 1]){
                p[n - 1] = b[n - 1];
            }
            else{
                p[n - 1] = a[n - 1];
            }
        }
        for (auto to : p){
            cout << to << " ";
        }
        cout << endl;
    }
    return 0;
}