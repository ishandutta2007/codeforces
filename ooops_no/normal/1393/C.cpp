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

mt19937 rnd(51);

const int N = 1e5 + 10;

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
        vector<int> v(n), have(n + 1);
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            have[v[i]]++;
        }
        for (int i = 1; i <= n; i++){
            if (have[i] != 0){
                a.pb({i, have[i]});
            }
        }
        int l = 0, r = n;
        while(r - l > 1){
            int mid = (r + l) / 2;
            //cout << "LLL" << mid << endl;
            vector<pair<int,int>> take(n, {-1, -1});
            set<pair<int,int>> st;
            for (auto to : a){
                st.insert({to.second, to.first});
            }
            bool x = 0;
            vector<int> ans(n);
            for (int i = 0; i < n; i++){
                if (take[i] != make_pair(-1, -1)){
                    st.insert({take[i]});
                }
                if (st.size() == 0){
                    x = 1;
                    break;
                }
                auto v = *st.rbegin();
                st.erase(v);
                if (v.first != 1){
                    if (i + mid + 1 >= n){
                        x = 1;
                        break;
                    }
                    else{
                        take[i + mid + 1] = {v.first - 1, v.second};
                    }
                }
                ans[i] = v.second;
            }
            if (!x){
                l = mid;
                /*for (auto to : ans){
                    cout << to << " ";
                }
                cout << endl << endl;*/
            }
            else{
                r = mid;
            }
        }
        cout << l << endl;/*cout << endl << endl << endl;*/
    }
    return 0;
}