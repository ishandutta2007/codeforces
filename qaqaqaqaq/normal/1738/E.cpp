#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N=100007;
const int INF=LLONG_MAX/10;
const int mod=998244353;
int n;
int a[N],f[N],rf[N];
int sum[N];
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    f[0]=rf[0]=1;
    for (int i=1;i<N;++i) f[i]=f[i-1]*i%mod;
    rf[N-1]=modpow(f[N-1],mod-2);
    for (int i=N-1;i>0;--i) rf[i-1]=rf[i]*i%mod;
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        for (int i=1;i<=n;++i) cin>>a[i];
        for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
        int L=0, R=n;
        int ans=1;
        bool aaa=1;
        while (L<R){
            if (sum[R]==sum[L]){
                for (int i=aaa;i<R-L;++i){
                    ans=ans*2%mod;
                }
                break;
            }
            int cntL=(!aaa), cntR=(!aaa),tmp=0;
            while (!a[L+1]) L++, cntL++;
            while (!a[R]) R--, cntR++;
            auto C=[&](int u,int v){
                return f[u]*rf[v]%mod*rf[u-v]%mod;
            };
            for (int i=0;i<=min(cntL,cntR);++i){
                tmp=(tmp+C(cntL,i)%mod*C(cntR,i))%mod;
            }
            ans=ans*tmp%mod;
            // cerr<<cntL<<" "<<cntR<<endl;
            int nowL=a[++L], nowR=0;
            while (nowL!=nowR&&L<R){
                while (nowL<nowR&&L<R) nowL+=a[++L];
                while (nowL>nowR&&L<R) nowR+=a[R--];
            }
            if (nowL==nowR&&sum[L]==sum[R]) ans=ans*2%mod;
            aaa=0;
            
        }
        cout<<ans<<"\n";
    }
}