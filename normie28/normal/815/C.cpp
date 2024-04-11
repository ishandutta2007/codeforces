
// Problem : C. Karen and Supermarket
// Contest : Codeforces - Codeforces Round #419 (Div. 1)
// URL : https://codeforces.com/problemset/problem/815/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define int long long 
//---------END-------//
int n,m,k,pos[100001],t,t1,i,j;
const int inf = 1e9 + 7;
const int max_n = 5228;
vector <int> G[max_n];
int dp[max_n][max_n][2];
int c[max_n], d[max_n];
int dfs(int v) {
    for (int i = 1; i < max_n; i++) dp[v][i][0] = dp[v][i][1] = inf;
    int sz = 1;
    dp[v][1][1] = c[v] - d[v];
    dp[v][1][0] = c[v];
    for (int u : G[v]) {
        int add = dfs(u);
        for (int j = sz; j >= 0; j--) {
            for (int i = add; i >= 0; i--) {
                dp[v][i + j][0] = min(dp[v][i + j][0], dp[v][j][0] + dp[u][i][0]);
                if (j) {
                    dp[v][i + j][1] = min(dp[v][i + j][1], dp[v][j][1] + min(dp[u][i][1], dp[u][i][0]));
                }
            }
        }
        sz += add;
    }    
    return sz;
}
signed main() {
	fio;
    int n, b;
    cin >> n >> b;
    int x;
    cin >> c[1] >> d[1];
    for (int i = 2; i <= n; i++) {
        cin >> c[i] >> d[i] >> x;
        G[x].push_back(i);
    } 
    dfs(1);
    int res = 0;
    while (res < n && min(dp[1][res + 1][1], dp[1][res + 1][0]) <= b) {
        res++;
    }
    cout << res;
}