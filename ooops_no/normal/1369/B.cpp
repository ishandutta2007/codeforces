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
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        bool x = 1, x1 = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                x1 = 1;
            }
            else{
                cnt++;
            }
            if (!x1){
                ans += '0';
            }
        }
        if (cnt != ans.size()){
            ans += '0';
        }
        for (int i = s.size() - 1; i > -1; i--){
            if (s[i] == '0') break;
            ans += '1';
        }
        cout << ans << endl;
    }
    return 0;
}