#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mod=998244353;
#define N 300'000

LL fac[N],ifac[N],a[N];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}
void upd(LL &x,LL y){x=(x+y)%mod;}
LL C(LL x,LL y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
void init(LL n){
    fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
}
void solve(){
    LL n;cin>>n;
    for (LL i=1;i<=n;++i) cin>>a[i];
    LL ans=1,s1=0,s2=0,c1=0,c2=0;
    for (LL l=0,r=n+1;l<r;){
        if (s1<s2){
            s1+=a[++l];
            c1=1;
            continue;
        }
        if (s2<s1){
            s2+=a[--r];
            c2=1;
            continue;
        }
        if (s1==s2){
            for (;a[l+1]==0&&l+1<r;++l) ++c1;
            for (;a[r-1]==0&&r-1>l;--r) ++c2;
            if (l+1==r){
                LL c=c1+c2-1,sum=0;
                for (LL i=0;i<=c;++i) upd(sum,C(c,i));
                ans=ans*sum%mod;
            }
            else{
                LL sum=0;
                for (LL i=0;i<=c1&&i<=c2;++i) upd(sum,C(c1,i)*C(c2,i));
                ans=ans*sum%mod;
            }
            s1+=a[++l];
            s2+=a[--r];
            c1=c2=1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init(200'000);
    LL T; cin>>T;
    while (T--) solve();
}