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
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = s.size();
        vector<vector<bool>> used(n, vector<bool>(2));
        bool x1 = 0;
        for (int i = 0; i < n; i++){
            if (i - x < 0 && i + x >= n){
                used[i][0] = 1;
                if (s[i] == '1'){
                    x1 = 1;
                }
                continue;
            }
            if (i - x < 0){
                if (s[i] == '1'){
                    used[i + x][1] = 1;
                }
                else{
                    used[i + x][0] = 1;
                }
            }
            else if (i + x >= n){
                if (s[i] == '1'){
                    if (used[i - x][0]) x1 = 1;
                    used[i - x][1] = 1;
                }
                else{
                    if (used[i - x][1]) x1 = 1;
                    used[i - x][0] = 1;
                }
            }
            else{
                if (s[i] == '1'){
                    if (!used[i - x][0]){
                        used[i - x][1] = 1;
                    }
                    else if (!used[i + x][0]){
                        used[i + x][1] = 1;
                    }
                    else{
                        x1 = 1;
                    }
                }
                else if (used[i - x][1] || used[i + x][1]){
                    x1 = 1;
                }
                else{
                    used[i - x][0] = used[i + x][0] = 1;
                }
            }
        }
        if (x1){
            cout << -1 << endl;
        }
        else{
            for (int i = 0; i < n; i++){
                if (used[i][0]) cout << 0;
                else cout << 1;
            }
            cout << endl;
        }
    }
    return 0;
}