#pragma GCC optimize ("Ofast")
/// #pragma GCC target("avx2")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int mod=1000000007ll;
int binpow(int a,int b){
    if (b==0) return 1ll;
    if (b%2) return (binpow(a,b-1)*a)%mod;
    else return binpow((a*a)%mod,b/2);
}
int F[200001];
int invF[200001];
inline int C(int n,int k){
    return ((F[n]*invF[k])%mod*invF[n-k])%mod;
}
int inv2[200001];
int t[200001];
int s[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,T;cin>>n>>T;
    for (int i=1;i<=n;i++) cin>>t[i],s[i]=s[i-1]+t[i];
    F[0]=1,invF[0]=1,inv2[0]=1;
    for (int i=1;i<=n;i++) F[i]=(F[i-1]*i)%mod;
    for (int i=1;i<=n;i++) invF[i]=(invF[i-1]*binpow(i,mod-2))%mod;
    for (int i=1;i<=n;i++) inv2[i]=(inv2[i-1]*binpow(2ll,mod-2))%mod;
    int res=0ll;
    s[n+1]=T+1;
    for (int i=1;i<=n;i++){
        for (int j=max(0ll,T-s[i+1]);j<=min(i,T-s[i]);j++){
            if (s[i+1]+j==T) res+=((inv2[i+1]*C(i,j))%mod*i)%mod;
            else res+=((inv2[i]*C(i,j))%mod*i)%mod;
            res%=mod;
        }
    }
    cout<<res;
    return 0;
}