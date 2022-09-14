#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=400000;
const ll mod=998244353ll;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll f[N+100];
ll rf[N+100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0]=1ll;
    for (ll i=1;i<=N;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[N]=binpow(f[N],mod-2);
    for (ll i=N;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ll D;cin>>D;
    vector<ll>p;
    ll d=2ll;
    while (d*d<=D){
        if (D%d==0){
            p.push_back(d);
        }
        while (D%d==0){
            D/=d;
        }
        d++;
    }
    if (D>1){
        p.push_back(D);
    }
    int q;cin>>q;
    for (;q>0;q--){
        ll a,b;cin>>a>>b;
        int sum1=0;
        int sum2=0;
        ll res=1ll;
        for (auto d:p){
            int cnta=0,cntb=0;
            while (a%d==0){
                a/=d;
                cnta++;
            }
            while (b%d==0){
                b/=d;
                cntb++;
            }
            res*=rf[abs(cnta-cntb)];
            res%=mod;
            if (cnta>cntb){
                sum1+=cnta-cntb;
            } else {
                sum2+=cntb-cnta;
            }
        }
        res*=f[sum1];
        res%=mod;
        res*=f[sum2];
        res%=mod;
        cout<<res<<endl;

    }
    return 0;
}