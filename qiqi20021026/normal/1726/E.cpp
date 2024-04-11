#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL mod=998244353;
#define N 320000
namespace REG{
LL gcd(LL x,LL y){return y==0?x:gcd(y,x%y);}
void upd(LL &x,LL y){x=(x+y)%mod;}
LL qpow(LL x,LL k){
    if (!k) return 1;
    LL tmp=qpow(x*x%mod,k>>1);
    return k&1?tmp*x%mod:tmp;
}
LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}
}
using namespace REG;
namespace NTT{//mod=998244353
LL rev[N<<2];
void ntt_init(LL &n){
    LL k=0; for (;1<<k<n;++k);
    n=1<<k; rev[0]=0;
    for (LL i=1;i<n;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
}
void ntt(LL *f,LL n){
    for (LL i=0;i<n;++i) if (i<rev[i]) swap(f[i],f[rev[i]]);
    for (LL i=0;1<<i<n;++i){
        LL t=1<<i,wn=qpow(3,(mod-1)/t/2);
        for (LL j=0;j<n;j+=t<<1){
            LL *f0=f+j,*f1=f+j+t,w=1;
            for (LL k=0;k<t;++k){
                LL tmp=f1[k]*w%mod;
                f1[k]=(f0[k]-tmp)%mod;
                f0[k]=(f0[k]+tmp)%mod;
                w=w*wn%mod;
            }
        }
    }
}
void intt(LL *f,LL n){
    ntt(f,n); reverse(f+1,f+n);
    for (LL i=0,I=inv(n);i<n;++i) f[i]=f[i]*I%mod;
}
}//namespace NTT
struct poly:vector<LL>{
    using vector<LL>::vector;
    LL time() const{return size()-1;}
    void dft(LL len){resize(len); NTT::ntt(data(),len);}
    void idft(LL len){resize(len); NTT::intt(data(),len);}
    poly operator % (const LL n) const{
        poly r=(*this);
        r.resize(n);
        return r;
    }
    poly operator %= (const LL n){
        resize(n);
        return (*this);
    }
};
poly operator * (poly a,poly b){
    LL len=a.size()+b.size()-1,lim=len;
    NTT::ntt_init(lim); a.dft(lim); b.dft(lim);
    for (LL i=0;i<lim;++i) a[i]=a[i]*b[i]%mod;
    a.idft(lim); a.resize(len);
    return a;
}
poly operator + (poly a,const poly &b){
    LL n=a.size(),m=b.size();
    a.resize(max(n,m));
    for (LL i=0;i<m;++i) upd(a[i],b[i]);
    return a;
}
poly operator - (poly a,const poly &b){
    LL n=a.size(),m=b.size();
    a.resize(max(n,m));
    for (LL i=0;i<m;++i) upd(a[i],-b[i]);
    return a;
}
poly f;
LL fac[N],ifac[N],fac2[N];
void init(LL n){
    fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
    fac2[0]=fac2[1]=1; for (LL i=2;i<=n;++i) fac2[i]=fac2[i-2]*i%mod;
    poly a(n+1),b(n+1);
    a[0]=1;
    for (LL i=2;i<=n;i+=2){
        a[i]=fac2[i-1]*ifac[i]%mod;
    }
    for (LL i=0;i<=n;++i) b[i]=ifac[i];
    f=a*b;
    for (LL i=0;i<=n;++i){
        f[i]=f[i]*fac[i]%mod;
    }
}
LL C(LL x,LL y){
    return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void solve(){
    LL n; cin>>n;
    LL ans=0;
    for (LL i=0,pw2=1;i*2<=n;i+=2){
        upd(ans,C(n-i,i)*f[n-i*2]%mod*(i==0?1:fac2[i-1])%mod*pw2);
        pw2=pw2*2%mod;
    }
    upd(ans,mod);
    cout<<ans<<'\n';
}
int main(){
    init(300000);
    LL T; cin>>T;
    while (T--) solve();

    return 0;
}