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
#define FILE_IN "tayto.inp"
#define FILE_OUT "tayto.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000003))
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
 
ll pow_mod(ll x, ll n) {
    ll ret = 1;
    for (; n; n>>=1) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}
 
ll n, k;
 
int main() {
    fio;
    cin>>n>>k;
    if (n<63 && (1LL<<n) < k) {
        cout<<1<<' '<<1;
        return 0;
    }
    ll B = pow_mod(2LL, n%(MOD-1)*((k%(MOD-1)-1+(MOD-1))%(MOD-1)));
    ll cnt = 0;
    for (ll i=k-1; i; i>>=1) cnt += (i>>1);
    ll igcd = pow_mod(2LL, cnt%(MOD-1)*(MOD-2)%(MOD-1));
    B = B * igcd % MOD;
    if (k-1 >= MOD) {
        cout<<B<<' '<<B;
        return 0;
    }
    ll A = 1;
    for (int i=1; i<=k-1; ++i) {
        A = A * ((pow_mod(2LL, n%(MOD-1))-i+MOD)%MOD) % MOD;
    }
    A = A * igcd % MOD;
    cout<<(B-A+MOD)%MOD<<' '<<B;
}