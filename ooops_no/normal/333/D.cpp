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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int v[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    int l = -1, r = 1e9 + 10;
    while(r - l > 1){
        int mid = (r + l) / 2, cnt = 0;
        vector<vector<int>> a(m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (v[i][j] >= mid){
                    a[j].pb(i);
                    cnt++;
                }
            }
        }
        if (cnt > max(5, (int)sqrt(max(n, m))) * max(n, m)){
            l = mid;
        }
        else{
            int sum[n][n];
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    sum[i][j] = 0;
                }
            }
            for (int j = 0; j < m; j++){
                for (int i = 0; i < a[j].size(); i++){
                    for (int ii = i + 1; ii < a[j].size(); ii++){
                        sum[a[j][i]][a[j][ii]]++;
                    }
                }
            }
            bool x = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (sum[i][j] > 1){
                        x = 1;
                    }
                }
            }
            if (x){
                l = mid;
            }
            else{
                r = mid;
            }
        }
    }
    cout << l << endl;
    return 0;
}