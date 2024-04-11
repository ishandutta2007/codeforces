#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=15;
const ll mod=1000000007;
ll a[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll p[N][N];
ll dp[(1<<N)];
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            p[i][j]=(a[i]*binpow((a[i]+a[j])%mod,mod-2))%mod;
        }
    }
    for (int mask=1;mask<(1<<n);mask++) dp[mask]=1;
    for (int mask=1;mask<(1<<n);mask++){
        for (int sub=(mask-1)&mask;sub>0;sub=(sub-1)&mask){
            ll mult=1ll;
            for (int j=0;j<n;j++){
                if ((sub&(1<<j))){
                    for (int i=0;i<n;i++){
                        if (mask&(1<<i) && !(sub&(1<<i))){
                            mult=(mult*p[j][i])%mod;
                        }
                    }
                }
            }
            dp[mask]+=mod-dp[sub]*mult%mod;
            dp[mask]%=mod;
        }
    }
//    for (int i=0;i<n;i++){
//        for (int mask=1;mask<(1<<n);mask++){
//            if (mask&(1<<i)) continue;
//
//        }
//    }
    ll res=0ll;
    for (int mask=1;mask<(1<<n);mask++){
        ll cn=__builtin_popcountll(mask);
        ll mult=1ll;
        for (int j=0;j<n;j++){
            if ((mask&(1<<j))){
                for (int i=0;i<n;i++){
                    if (!(mask&(1<<i))){
                        mult=(mult*p[j][i])%mod;
                    }
                }
            }
        }
        res+=cn*dp[mask]%mod*mult;
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887
*/