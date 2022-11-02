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

const int N = 5010;
int dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 1e18;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            dp[i][j] = 1e18;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int j = 0; j <= 5000; j++){
        if (v[0] > j){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = 0;
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 5000; j >= 0; j--){
            if (v[i] > j){
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else {
                dp[i][v[i]] = min(dp[i][v[i]], dp[i - 1][j] + abs(j - v[i]));
            }
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
        }
        for (int j = 0; j <= 5000; j++){
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    for (int j = 0; j <= 5000; j++){
        ans = min(ans, j + dp[n - 1][j]);
    }
    cout << ans << endl;
    return 0;
}