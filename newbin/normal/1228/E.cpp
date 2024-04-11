#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 300;
const ll mod = 1e9 + 7;
ll qm(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a%mod;
        a = a*a%mod; b>>=1;
    }return res;
}
int n;
ll k;
ll p[maxn], pp[maxn];
ll fac[maxn], ifac[maxn];
ll Com(int n, int m){
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll dp[maxn][maxn];
int main()
{
    fac[0] = ifac[0] = 1; pp[0] = p[0] = 1;
	cin>>n>>k;
	  for(int i = 1; i < maxn; ++i){
        fac[i] = fac[i-1]*i%mod;
        ifac[i] = qm(fac[i], mod-2);
        p[i] = p[i-1] * k %mod;
        pp[i] = pp[i-1]*(k-1)%mod;
    }
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = 0;
            int t;
            if(i == 1) t = 0; else t = 1;
            for(; t <= j; ++t){
                dp[i][j] = (dp[i][j] + dp[i-1][t]*Com(n-t,j-t)%mod *p[t] % mod * pp[n-j] % mod) %mod;
            }
            dp[i][j] = (dp[i][j] - dp[i-1][j]*pp[n]%mod)%mod;
           // cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
        }
       // if(i != 1)
        //    dp[i][n] = (dp[i][n] - dp[i-1][n]*pp[n]%mod)%mod;
	}
	dp[n][n] %= mod;
	dp[n][n] = (dp[n][n] + mod) %mod;
	cout<<dp[n][n]<<endl;
}