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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        vector<int> a(3), b(3);
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
        int ans = min(a[2], b[1]);
        a[2] -= ans;
        b[1] -= ans;
        for (int i = 2; i > 0; i--){
            int mn = min(a[0], b[i]);
            b[i] -= mn, a[0] -= mn;
        }
        for (int i = 1; i > 0; i--){
            int mn = min(b[0], a[i]);
            a[i] -= mn, b[0] -= mn;
        }
        for (int i = 0; i < 3; i++){
            int mn = min(a[i], b[i]);
            a[i] -= mn;
            b[i] -= mn;
        }
        cout << ans * 2 - min(b[2], a[1]) * 2 << endl;
    }
    return 0;
}