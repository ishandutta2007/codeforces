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
#define int __int128
 
mt19937 rnd(51);
 
const int N = 2e5 + 10;
vector<vector<int>> t(4 * N, vector<int>(2, -1e15)), add(4 * N, vector<int>(2));
 
void push(int v, int tt){
    t[v][tt] += add[v][tt];
    if (v * 2 < 4 * N){
        add[v * 2][tt] += add[v][tt];
        add[v * 2 + 1][tt] += add[v][tt];
    }
    add[v][tt] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int val, int tt){
    if (l > r) return;
    push(v, tt);
    if (tl == l && tr == r){
        add[v][tt] += val;
        push(v, tt);
        return;
    }
    push(v, tt);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val, tt);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val, tt);
    t[v][tt] = max(t[v * 2][tt], t[v * 2 + 1][tt]);
}
 
int get(int v, int tl, int tr, int l, int r, int tt){
    push(v, tt);
    if (l > r) return -1e15;
    if (tl == l && tr == r){
        push(v, tt);
        return t[v][tt];
    }
    push(v, tt);
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm), tt), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, tt));
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n = 3, m;
    cin >> m;
    long long v[n][m];
    vector<vector<int>> dp(n, vector<int>(m, -1e15));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    dp[0][0] = v[0][0];
    dp[1][0] = v[1][0] + dp[0][0];
    dp[2][0] = v[2][0] + dp[1][0];
    update(1, 0, m - 1, 0, 0, max((int)1e15 + dp[2][0], (int)1e15 + dp[0][0]), 0);
    update(1, 0, m - 1, 0, 0, 1e15 + dp[2][0], 1);
    for (int j = 1; j < m; j++){
        update(1, 0, m - 1, 0, j - 1, v[0][j] + v[1][j] + v[2][j], 0);
        update(1, 0, m - 1, 0, j - 1, v[0][j] + v[1][j] + v[2][j], 1);
        for (int i = 0; i < n; i++){
            if (i == 0){
                dp[i][j] = max({dp[0][j], dp[0][j - 1] + v[0][j], dp[1][j - 1] + v[0][j] + v[1][j], dp[2][j - 1] + v[2][j] + v[1][j] + v[0][j]});
                update(1, 0, m - 1, j, j, 1e15 + dp[i][j], 0);
                dp[i][j] = max(dp[i][j], get(1, 0, m - 1, 0, j - 1, 1));
            }
            if (i == 1){
                dp[i][j] = max({dp[1][j], dp[1][j - 1] + v[1][j], dp[0][j - 1] + v[1][j] + v[0][j], dp[2][j - 1] + v[2][j] + v[1][j]});
            }
            if (i == 2){
                dp[i][j] = max({dp[2][j], dp[2][j - 1] + v[2][j], dp[1][j - 1] + v[2][j] + v[1][j], dp[0][j - 1] + v[2][j] + v[1][j] + v[0][j]});
                update(1, 0, m - 1, j, j, 1e15 + dp[i][j], 1);
                dp[i][j] = max(dp[i][j], get(1, 0, m - 1, 0, j - 1, 0));
            }
        }
    }
    long long val = dp[2][m - 1];
    cout << val;
    return 0;
}