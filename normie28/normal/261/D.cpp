
// Problem : D. Parcels
// Contest : Codeforces - Codeforces Round #274 (Div. 1)
// URL : https://codeforces.com/contest/480/problem/D
// Memory Limit : 256 MB
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
typedef long long ll;
//---------END-------//

const int DIM = 1e5 + 5;
const long long INF = 1e18;
 
int k, n, m, t;
int a[DIM];
int first[DIM];
 
int **Next;
long long **dp;
 
vector <int> v;
void solve(int m) {
    v.clear();
    for (int i = 1; i <= n ; ++i) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (t > v.size()) {
        printf("%d\n", v.size());
        return ;
    }
 
    if (v.size() < m) {
        m = v.size();
        for (int i = 1; i <= n ; ++i)
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
 
    memset(first, 0, sizeof(first));
    for (int i = 1; i <= n ; ++i) {
        if (first[a[i]] == 0) first[a[i]] = i;
        for (int j = 1; j <= m ; ++j) Next[i][j] = -1;
    }
 
    for (int i = n - 1; i >= 1 ; --i) {
        for (int j = 1; j <= m ; ++j) Next[i][j] = Next[i + 1][j];
        Next[i][a[i + 1]] = i + 1;
    }
 
    for (int i = 1; i <= n ; ++i) {
        for (int j = 0; j <= m ; ++j)
            dp[i][j] = INF;
    }
 
    for (int i = 1; i <= n ; ++i)
        dp[1][a[i]] = min(dp[1][a[i]], 1LL * i);
 
    for (int j = 2; j <= m ; ++j)
        dp[1][j] = min(dp[1][j], dp[1][j - 1]);
 
    int Sol = 1;
    for (int i = 2; i <= n ; ++i) {
        for (int j = i; j <= m ; ++j) {
            if (first[j] == 0) continue ;
            int pos = dp[i - 1][j - 1] % n;
            if (pos == 0) pos = n;
 
            if (Next[pos][j] == -1) dp[i][j] = min(dp[i][j], 1LL * ((dp[i - 1][j - 1] - 1) / n + 1) * n + first[j]);
            else dp[i][j] = min(dp[i][j], 1LL * ((dp[i - 1][j - 1] - 1) / n ) * n + Next[pos][j]);
        }
 
        for (int j = i; j <= m ; ++j) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if (dp[i][j] <= 1LL * n * t) Sol = i;
        }
 
        if (Sol < i) break ;
    }
 
    printf("%d\n", Sol);
}
 
int main()
{
    scanf("%d%d%d%d", &k, &n, &m, &t);
 
    Next = new int*[n + 1];
    dp = new long long*[n + 1];
    for (int i = 1; i <= n ; ++i) {
        Next[i] = new int[m + 1];
        dp[i] = new long long[m + 1];
    }
 
    while (k--) solve(m);
 
    return 0;
}