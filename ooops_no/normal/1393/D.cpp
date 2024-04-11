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

const int N = 1e5 + 10;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int l[n][m], r[n][m], ans[n][m], ans1[n][m];
    char v[n][m];
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            v[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            l[i][j] = 1;
            if (j - 1 >= 0 && v[i][j - 1] == v[i][j]){
                l[i][j] = max(l[i][j], l[i][j - 1] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = m - 1; j > -1; j--){
            r[i][j] = 1;
            if (j + 1 < m && v[i][j] == v[i][j + 1]){
                r[i][j] = max(r[i][j], r[i][j + 1] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans[i][j] = 1;
            if (i - 1 >= 0 && v[i][j] == v[i - 1][j]){
                ans[i][j] = max(ans[i][j], min(r[i][j], min(l[i][j], ans[i - 1][j] + 1)));
            }
        }
    }
    for (int i = n - 1; i > -1; i--){
        for (int j = 0; j < m; j++){
            ans1[i][j] = 1;
            if (i + 1 < n && v[i + 1][j] == v[i][j]){
                ans1[i][j] = max(ans1[i][j], min(r[i][j], min(l[i][j], ans1[i + 1][j] + 1)));
            }
        }
    }
    int lol = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            lol += min(ans[i][j], ans1[i][j]);
        }
    }
    cout << lol << endl;
    return 0;
}