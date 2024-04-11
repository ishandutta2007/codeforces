#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
ll mod=1000000007ll;
ll binpow(ll a,ll b){
    if (b==0) return 1ll;
    if (b%2) return (binpow((a*a)%mod,(b-1ll)/2ll)*a)%mod;
    else return binpow((a*a)%mod,b/2ll)%mod;
}
ll dp[10011][51];
ll d[301];
ll p[20001];
map<ll,int>mp;
int32_t main() {
    ll n,k;cin>>n>>k;
    ll a=n;
    vector<ll>v;
    ll d=2ll;

    while (d*d<=n && n>1){
        int cnt=0;
        while (n%d==0){
             n/=d;
             cnt++;
        }
        if (cnt){
            p[(int)v.size()]=d;
            v.push_back(cnt);
        }
        d++;
    }
    if (n>1){
        p[(int)v.size()]=n;
        v.push_back(1);
    }
    ll res=1ll;
    for (int t=0;t<v.size();t++){
        ll cur=1ll;
        for (int i=0;i<=v[t];i++) {
             dp[0][i]=cur;
             cur*=p[t];
        }
        for (int i=1;i<=k;i++){
            ll sum=0ll;
            ll cnt=0ll;
            for (int j=0;j<=v[t];j++){
                sum+=dp[i-1][j];
                sum%=mod;
                cnt++;
                dp[i][j]=(sum*binpow(cnt,mod-2ll))%mod;

            }
        }
        res*=dp[k][v[t]];
        res%=mod;
    }
    cout<<res;
    return 0;
}