
// Problem : C. Beavermuncher-0xFF
// Contest : Codeforces - Codeforces Beta Round #69 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/77/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define mp make_pair
#define pb push_back
typedef long double ld;
//---------END-------//
const int maxn = 2e5 + 2;
const ll inf = 1e18 + 43;
const int mod = 1e9+7;
const int maxlog = 20;
const ld pi = 3.1415926535897932384626433832795028841971693993751;
ll a[maxn];
vector<int> adj[maxn];
ll dp[maxn] , r[maxn];
void dfs(int v , int p){
    vector<ll> vec;
    ll sum_r = 0;
    for(int i = 0 ; i < adj[v].size() ; i ++ ){
        int u = adj[v][i];
        if(u == p)
            continue;
        a[u] -- ;
        dfs(u , v);
        vec.pb(1 + dp[u]);
        sum_r += r[u];
    }
    r[v] = a[v];
    ll cnt = min(a[v] , (ll) vec.size());
    r[v] -= cnt;
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    for(int i = 0 ; i < cnt ; i ++ )
        dp[v] += vec[i];
    dp[v] += cnt;
    cnt = min(r[v] , sum_r);
    r[v] -= cnt;
    dp[v] += 2 * cnt;
}
int main()
{
    fio;
    cout.precision(20);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n - 1 ; i ++ ){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int s;
    cin >> s;
    dfs(s , 0);
    cout << dp[s];
}