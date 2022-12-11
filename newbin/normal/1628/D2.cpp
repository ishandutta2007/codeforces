#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int mod = 1e9+7;
const int maxn = 2e6+50;
int pw[maxn];
const int inv2 = (mod+1)/2;
int k;
int qm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (ll)res*a%mod;
        a = (ll)a*a%mod; b >>= 1;
    }return res;
}
int fac[maxn], ifac[maxn];
int C(int n, int m){
    assert(m <= n && m >= 0);
    return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
    fac[0] = ifac[0] = 1;
    pw[0] = 1;
    fors(i,1,maxn) fac[i] = (ll)i*fac[i-1]%mod, ifac[i] = qm(fac[i], mod-2), pw[i] = (ll)pw[i-1]*inv2%mod;
    int T; cin>>T;
    while(T--){
        int n, m, k;
        cin>>n>>m>>k;
        if(n == m){
            ll ans = (ll)n*k%mod;
            cout<<ans<<endl; continue;
        }
        int p = 0;
        int len = n-m;
        int N = len-1;
        ll ans = 0;
        for(int i = m; i >= 1; --i){
            ans = (ans + (ll)pw[len]*C(N, p)%mod*i%mod*k%mod)%mod;
            // cout<<"ans:"<<ans<<" len:"<<len<<" C:"<<C(N,p)<<" p:"<<p<<endl;
            len ++;
            N++; p++;
        }
        cout<<ans<<endl;
    }
    return 0;
}