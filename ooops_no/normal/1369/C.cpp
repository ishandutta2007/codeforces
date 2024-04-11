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
        int n, k, sum = 0;
        cin >> n >> k;
        vector<int> v(n), a(k);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        for (int i = 0; i < k; i++){
            cin >> a[i];
        }
        sort(v.rbegin(), v.rend());
        sort(a.begin(), a.end());
        for (int i = 0; i < k; i++){
            if (a[i] == 1){
                sum += v[i] * 2;
            }
            else{
                sum += v[i];
            }
        }
        int kk = k;
        for (int i = 0; i < kk; i++){
            if (a[i] == 1) continue;
            sum += v[k + a[i] - 2];
            k += a[i] - 1;
        }
        cout << sum << endl;
    }
    return 0;
}