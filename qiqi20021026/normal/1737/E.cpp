#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 1200000

const LL mod=10000'00007;
LL pw[N],f[N],g[N],G[N],n;

void upd(LL &x,LL y){x=(x+y)%mod;}
LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

void solve(){
    cin>>n;
    pw[0]=1;
    for (LL i=1;i<=n;++i){
        pw[i]=pw[i-1]*2%mod;
    }
    f[1]=1;
    for (LL i=2;i<=n;++i){
        LL j=i/2;
        f[i]=pw[j];
    }
    f[n]=f[n]*2%mod;
    g[n]=1; G[n]=1;
    for (LL i=n-1;i;--i){
        g[i]=(G[i+1]-G[min(i+i,n+1)])%mod;
        if (n<i+i) ++g[i];
        G[i]=(G[i+1]+g[i])%mod;
    }
    LL I=inv(pw[n]);
    for (LL i=1;i<=n;++i){
        LL ans=f[i]*g[i]%mod*I%mod;
        upd(ans,mod);
        cout<<ans<<'\n';
        f[i]=g[i]=G[i]=pw[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--) solve();
}