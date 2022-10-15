
// Problem : E. Beads
// Contest : Codeforces - Codeforces Beta Round #8
// URL : https://codeforces.com/problemset/problem/8/E
// Memory Limit : 64 MB
// Time Limit : 5000 ms
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
typedef long long ll;
//---------END-------//
 
const int MAXN = 51;
 
ll dp[MAXN][MAXN][2][2], k;
int n, templ[MAXN];
 
ll calc(int l, int r, int eq0, int eq1) {
    if(l > r) return 1;
    ll &res = dp[l][r][eq0][eq1];
    if(~res) return res;
    res = 0;
    for(int i = 0; i <= 1; i++) {
        if(~templ[l] && templ[l] != i) continue;
        for(int j = 0; j <= 1; j++) {
            if(~templ[r] && templ[r] != j) continue;
            if(eq0 && i > j || eq1 && i > (j ^ 1) || l == r && i != j) continue;
            res += calc(l + 1, r - 1, eq0 && i == j, eq1 && i != j);
        }
    }
    return res;
}
 
ll solve() {
    memset(dp, -1, sizeof(dp));
    return calc(1, n, 1, 1);
}
 
int main() {
	fio;
	cin>>n>>k;
    memset(templ, -1, sizeof(templ)); templ[1] = 0;
    if(solve() <= k) return cout<<-1, 0;
    for(int i = 2; i <= n; i++) {
        templ[i] = 0; ll t = solve();
        if(k >= t) {
            templ[i] = 1; k -= t;
        }
    }
    for(int i = 1; i <= n; i++) cout<< templ[i];
}