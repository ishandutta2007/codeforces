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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> r(n), g(m), b(k);
    for (int i = 0; i < n; i++){
        cin >> r[i];
    }
    for (int i = 0; i < m; i++){
        cin >> g[i];
    }
    for (int i = 0; i < k; i++){
        cin >> b[i];
    }
    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(b.rbegin(), b.rend());
    int dp[n + 1][m + 1][k + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int l = 0; l <= k; l++){
                dp[i][j][l] = 0;
            }
        }
    }
    deque<pair<int, pair<int,int>>> q;
    q.push_back({0, {0, 0}});
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        q.pop_front();
        ans = max(ans, dp[v.first][v.second.first][v.second.second]);
        if (v.first != n && v.second.first != m){
            if (dp[v.first + 1][v.second.first + 1][v.second.second] == 0){
                q.push_back({v.first + 1, {v.second.first + 1, v.second.second}});
            }
            dp[v.first + 1][v.second.first + 1][v.second.second] = max(dp[v.first + 1][v.second.first + 1][v.second.second], dp[v.first][v.second.first][v.second.second] + r[v.first] * g[v.second.first]);
        }
        if (v.second.first != m && v.second.second != k){
            if (dp[v.first][v.second.first + 1][v.second.second + 1] == 0){
                q.push_back({v.first, {v.second.first + 1, v.second.second + 1}});
            }
            dp[v.first][v.second.first + 1][v.second.second + 1] = max(dp[v.first][v.second.first + 1][v.second.second + 1], dp[v.first][v.second.first][v.second.second] + g[v.second.first] * b[v.second.second]);
        }
        if (v.second.second != k && v.first != n){
            if (dp[v.first + 1][v.second.first][v.second.second + 1] == 0){
                q.push_back({v.first + 1, {v.second.first, v.second.second + 1}});
            }
            dp[v.first + 1][v.second.first][v.second.second + 1] = max(dp[v.first + 1][v.second.first][v.second.second + 1], dp[v.first][v.second.first][v.second.second] + b[v.second.second] * r[v.first]);
        }
    }
    cout << ans << endl;
    return 0;
}