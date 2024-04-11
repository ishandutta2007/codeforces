//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
const int N=1000010;
const ll mod=998244353;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
int a[N];
int cnt[N];
ll P[N];
ll dp[N];
ll f[N];
ll rf[N];
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
void solve(){
    int n;cin>>n;
    f[0]=rf[0]=1ll;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        rf[i]=binpow(f[i],mod-2);
    }
    for (int i=1;i<=n;i++){
        cnt[i]=0;
    }
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    bool eq=true;
    for (int i=2;i<=n;i++){
        eq&=(a[i]==a[1]);
    }
    if (eq){
        cout<<1<<endl;
        return;
    }
    int g=0;
    for (int i=1;i<=n;i++) g=__gcd(g,cnt[i]);
    vector<int>d;
    for (int i=1;i<=g;i++){
        if (g%i==0) d.push_back(i);
    }
    for (int i=(int)d.size()-1;i>=0;i--){
        P[i]=f[n/d[i]];
        dp[i]=0ll;
        for (int j=1;j<=n;j++){
            P[i]*=rf[cnt[j]/d[i]];
            P[i]%=mod;
        }
        for (int j=1;j<=n;j++){
            if (cnt[j]/d[i]>=2){
                ll CNT=P[i]*rf[n/d[i]]%mod*f[n/d[i]-2]%mod*f[cnt[j]/d[i]]%mod*rf[cnt[j]/d[i]-2]%mod;
//                cout<<i<<" "<<j<<" "<<CNT<<endl;
                dp[i]+=CNT;
                dp[i]%=mod;
            }
        }
        dp[i]*=n;
        dp[i]%=mod;
        for (int j=i+1;j<d.size();j++){
            if (d[j]%d[i]==0){
                dp[i]+=mod-dp[j];
                dp[i]%=mod;
                P[i]+=mod-P[j];
                P[i]%=mod;
            }
        }
    }
    ll res=0ll;
    ll TOT=0ll;
    for (int i=0;i<d.size();i++){
        res+=dp[i]*binpow(n/d[i],mod-2);
        res%=mod;
        TOT+=P[i]*binpow(n/d[i],mod-2);
        TOT%=mod;
    }
    res*=binpow(TOT,mod-2);
    res%=mod;
    cout<<(mod+n-res)%mod<<endl;
}

int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
6
1 2 3 1 2 3

**/
/**
13
1 2 3 2 1 3 3 4 5 5 5 4 7
0 1 1 1 1 1 0 0 1 1 1 0 0
**/