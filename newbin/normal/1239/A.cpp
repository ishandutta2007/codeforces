#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 50;
ll qm(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }return res;
}
ll fac[maxn], ifac[maxn];
ll C(int n, int k){
    if(k > n) return 0;
    return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
int main()
{
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < maxn; ++i) {
        fac[i] = fac[i-1]*i%mod;
        ifac[i] = qm(fac[i], mod-2);
    }
    int n, m;
    cin>>n>>m;
    ll ans = 1;
    for(int i = 1; i <= n/2; ++i){
        ans += C(n-2*i+i, i);
        ans %= mod;
    }
    for(int i = 1; i <= m/2; ++i){
        ans += C(m-2*i+i, i);
        ans %= mod;
    }
    ans = (ans*2)%mod;
    cout<<ans<<endl;
}