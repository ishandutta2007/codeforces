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
        int n;
        ld L, now = 0, s = 1, s1 = 1, ans = 0;
        cin >> n >> L;
        vector<ld> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int l = 0, r = n - 1;
        while(1){
            ld meet = (L - now) / (s + s1);
            ld d = (a[l] - now) / s;
            ld d1 = (L - a[r]) / s1;
            if (meet < min(d, d1)){
                ans += meet;
                break;
            }
            if (d < d1){
                now += s * d, L -= s1 * d;
                s++;
                l++;
            }
            else{
                now += s * d1, L -= s1 * d1;
                s1++;
                r--;
            }
            ans += min(d, d1);
            if (l > r){
                ans += (L - now) / (s + s1);
                break;
            }
        }
        cout << setprecision(20) << fixed << ans << endl;
    }
    return 0;
}