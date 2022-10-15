
// Problem : D. Kindergarten
// Contest : Codeforces - Codeforces Round #276 (Div. 1)
// URL : https://codeforces.com/problemset/problem/484/D
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
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
const ll INF = 1e10;
const ll MAXN = 1e6 + 10;
 
struct Node {
    ll res,minim,maxim;
    Node() {}
    Node(ll a,ll mn,ll mx){
        res = a,minim = mn,maxim = mx;
    }
};
 
Node dp[2][MAXN];
ll a[MAXN],n;
 
void solve(){ 
    cin>>n;
 
    FOR(i,1,n) cin>>a[i];
 
    dp[0][1] = dp[1][1] = Node(0,a[1],a[1]);
 
    FOR(i,2,n){
        dp[1][i] = dp[0][i-1];
        dp[1][i].minim = dp[1][i].maxim = a[i];
 
        Node p1 = dp[0][i-1];
        if(a[i] < p1.minim){
            p1.res += p1.minim - a[i];
            p1.minim = a[i];
        }else if(a[i] > p1.maxim){
            p1.res += a[i] - p1.maxim;
            p1.maxim = a[i];
        }
 
        Node p2 = dp[1][i-1];
        if(a[i] < p2.minim){
            p2.res += p2.minim - a[i];
            p2.minim = a[i];
        }else if(a[i] > p2.maxim){
            p2.res += a[i] - p2.maxim;
            p2.maxim = a[i];
        }
 
        if(p1.res > p2.res) dp[0][i] = p1;
        else dp[0][i] = p2;
    }
 
    ll res = 0;
 
    FOR(i,1,n) res = max(res,max(dp[0][i].res,dp[1][i].res));
    cout<<res<<endl;
}   
 
signed main(){
 
 fio; 
 
 solve();
}