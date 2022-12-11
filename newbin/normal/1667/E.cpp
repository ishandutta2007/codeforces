#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define mid ((r+l)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1,mid+1,r
#define pb push_back
#define lowbit(x) (x&(-x))
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 998244353;
int qm(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (ll)res*a%mod;
        a = (ll)a*a%mod; b >>= 1;
    }return res;
}
const int maxn = 2e5 + 5;
int fac[maxn], ifac[maxn], inv[maxn];
int C(int n, int m){
    if(m<0||m>n) return 0;
    return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void init(){
    fac[0] = ifac[0] = 1;
    fors(i,1,maxn) fac[i] = (ll)i*fac[i-1]%mod, ifac[i] = qm(fac[i], mod-2), inv[i]=qm(i,mod-2);
}
int dp[maxn];
int main(){
    init();
    int n; cin>>n; int s = (n+1)/2;
    for(int i = n; i > 0; --i){
        dp[i] = (ll)fac[n-i]*fac[i-1]%mod*C(n-s,i-1)%mod;
        dp[i] = (dp[i]-(ll)inv[i]*dp[i+1])%mod;
        dp[i] = (dp[i]+dp[i+1])%mod;
    }
    fors(i,1,n+1){
        int ans = (dp[i]-dp[i+1])%mod; ans = (ans+mod)%mod;
        cout<<ans<<" ";
    }
    return 0;
};