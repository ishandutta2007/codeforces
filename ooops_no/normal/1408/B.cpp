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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> st;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }
        if (st.size() == k){
            cout << 1 << endl;
        }
        else{
            if (k == 1){
                cout << -1 << endl;
            }
            else{
                int l = 0, r = 1e9;
                while(r - l > 1){
                    int mid = (r + l) / 2;
                    int cnt = (mid) * (k - 1) + 1;
                    if (cnt >= st.size()){
                        r = mid;
                    }
                    else{
                        l = mid;
                    }
                }
                cout << r << endl;
            }
        }
    }
    return 0;
}