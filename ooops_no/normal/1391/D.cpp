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
    int n, m;
    cin >> n >> m;
    if (n >= 4 && m >= 4){
        for (int i = 0; i < n * m; i++){
            char c;
            cin >> c;
        }
        cout << -1 << endl;
    }
    else if (n < 4 && m < 4){
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c;
                cin >> c;
                v[i][j] = c - '0';
            }
        }
        int ans = 1e18;
        for (int i = 0; i < (1 << (n * m)); i++){
            int cnt = 0, x = 0;
            for (int j = 0; j < (n * m); j++){
                if (i & (1 << j)){
                    v[j / m][j % m] = (v[j / m][j % m] + 1) % 2;
                    cnt++;
                }
            }
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < m - 1; j++){
                    if ((v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1]) % 2 == 0){
                        x = 1;
                    }
                }
            }
            if (!x){
                ans = min(ans, cnt);
            }
            for (int i = 0; i < (1 << (n * m)); i++){
                for (int j = 0; j < (n * m); j++){
                    if (i & (1 << j)){
                        v[j / m][j % m] = (v[j / m][j % m] + 1) % 2;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    else{
        bool x = 0;
        if (n > m){
            x = 1;
            swap(n, m);
        }
        vector<vector<int>> v(n, vector<int>(m));
        if (x) swap(n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char c;
                cin >> c;
                if (x){
                    v[j][i] = c - '0';
                }
                else{
                    v[i][j] = c - '0';
                }
            }
        }
        if (n == 1 || m == 1){
            cout << 0 << endl;
            return 0;
        }
        if (x){
            swap(n, m);
        }
        vector<vector<int>> dp(m, vector<int>(1 << n, 1e18));
        for (int i = 0; i < (1 << n); i++){
            int ans = 0;
            for (int j = 0; j < n; j++){
                int v11 = (bool)(i & (1 << j));
                if (v[j][0] != v11){
                    ans++;
                }
            }
            dp[0][i] = ans;
        }
        for (int i = 1; i < m; i++){
            for (int j = 0; j < (1 << n); j++){
                for (int k = 0; k < (1 << n); k++){
                    int pl = 0;
                    for (int l = 0; l < n; l++){
                        if (v[l][i] != (bool)(k & (1 << l))){
                            pl++;
                        }
                    }
                    int sum = (bool)(j & (1 << 0)) + (bool)(j & (1 << 1)) + (bool)(k & (1 << 0)) + (bool)(k & (1 << 1));
                    if (sum % 2 == 1){
                        if (n == 3){
                            sum = (bool)(j & (1 << 1)) + (bool)(j & (1 << 2)) + (bool)(k & (1 << 1)) + (bool)(k & (1 << 2));
                            if (sum % 2 == 1){
                                dp[i][k] = min(dp[i][k], dp[i - 1][j] + pl);
                            }
                        }
                        else{
                            dp[i][k] = min(dp[i][k], dp[i - 1][j] + pl);
                        }
                    }
                }
            }
        }
        int ans = dp[m - 1][0];
        for (int i = 0; i < (1 << n); i++){
            ans = min(ans, dp[m - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}