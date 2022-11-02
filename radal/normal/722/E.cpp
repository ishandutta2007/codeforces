#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e3+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
ll dp[N][30];
int fa[maxm],fa2[maxm];
int pre[N];
inline int c(int n,int r){
    if (r > n) return 0;
    if (r == n) return 1;
    return (1ll*(1ll*fa[n]*fa2[r])%mod*fa2[n-r])%mod;
}
pll p[N];
int main(){
    ios :: sync_with_stdio(0);  cin.tie(0);
    fa[0] = 1;
    fa2[0] = 1;
    rep(i,1,maxm){
        fa[i] = (1ll*fa[i-1]*i)%mod;
        fa2[i] = poww(fa[i],mod-2);
    }
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    rep(i,0,k) cin >> p[i].X >> p[i].Y;
    sort(p,p+k);
    p[k].X = n,p[k].Y = m;
    k++;
    rep(i,0,k){
        dp[i][0] = c(p[i].X+p[i].Y-2,p[i].X-1);
        rep(j,0,i){
            dp[i][0] = dp[i][0]+mod-(dp[j][0]*c(p[i].X-p[j].X+p[i].Y-p[j].Y,p[i].X-p[j].X))%mod;
            dp[i][0] %= mod;
        }
        pre[i] = dp[i][0];
    }
    rep(i,1,21){
        rep(j,0,k){
            dp[j][i] = c(p[j].X+p[j].Y-2,p[j].X-1);
            rep(x,0,j){
                dp[j][i] += mod-(dp[x][i]*c(p[j].X+p[j].Y-p[x].X-p[x].Y,p[j].X-p[x].X))%mod;
                dp[j][i] %= mod;
            }
            dp[j][i] = (dp[j][i]+mod-pre[j])%mod;
            pre[j] = (pre[j]+dp[j][i])%mod;
        }
    }
    rep(i,0,k) dp[i][21] = (c(p[i].X+p[i].Y-2,p[i].X-1)-pre[i]+mod)%mod;
    k--;
    ll ans = 0;
    rep(i,0,22){
        ans += dp[k][i]*s;
        ans %= mod;
        s = (s+1)/2;
    }
    cout << (ans*poww(c(n+m-2,n-1),mod-2))%mod;
    return 0;
}