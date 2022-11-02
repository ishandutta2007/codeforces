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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans;
        int mxnow = 1e18;
        for (int i = 0; i <= n - 2; i++){
            int dif = abs(x - y);
            if (dif % (i + 1) == 0){
                vector<int> anss;
                int now = x + dif / (i + 1);
                for (int j = 0; j < i; j++){
                    anss.pb(now);
                    now += dif / (i + 1);
                }
                anss.pb(x);
                anss.pb(y);
                int m = n - anss.size();
                now = x - dif / (i + 1);
                while(now > 0 && m > 0){
                    anss.pb(now);
                    now -= dif / (i + 1);
                    m--;
                }
                now = y + dif / (i + 1);
                while(m > 0){
                    anss.pb(now);
                    now += dif / (i + 1);
                    m--;
                }
                int mx = anss[0];
                for (int j = 0; j < anss.size(); j++){
                    mx = max(mx, anss[j]);
                }
                if (mx < mxnow){
                    mxnow = mx;
                    ans = anss;
                }
            }
        }
        for (auto to : ans){
            cout << to << " ";
        }
        cout << endl;
    }
    return 0;
}