#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 40+20,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int dp[N][N][N];
vector<pll> ve[N];
pair<pll,pll> b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,h,m;
    cin >> n >> h >> m;
    rep(i,0,m){
        int l,r,x,c;
        cin >> l >> r >> x >> c;
        l--;
        b[i] = {{l,r},{x,c}};
        rep(j,l,r) ve[j].pb({x,i});
    }
    rep(i,0,n) sort(all(ve[i]));
    repr(l,n-1,0){
        rep(r,l+1,n+1){
            rep(i,0,h+1){
                if (r-l == 1){
                    int sum = 0;
                    for(pll p : ve[l]){
                        if (p.X > i)
                            break;
                        int j = p.Y;
                        dp[l][r][i] = max(dp[l][r][i],p.X*p.X-sum);
                        if(b[j].X.Y-b[j].X.X == 1)
                            sum += b[j].Y.Y;
                    }
                    dp[l][r][i] = max(dp[l][r][i],i*i-sum);
                    continue;
                }
                rep(k,l,r){
                    int sum = 0;
                    for(pll p : ve[k]){
                        if (p.X > i)
                            break;
                        int j = p.Y;
                        dp[l][r][i] = max(dp[l][r][i],p.X*p.X-sum+dp[l][k][p.X]+dp[k+1][r][p.X]);
                        if(b[j].X.Y <= r && b[j].X.X >= l)
                            sum += b[j].Y.Y;
                    }
                    dp[l][r][i] = max(dp[l][r][i],i*i-sum+dp[l][k][i]+dp[k+1][r][i]);
                }
            }
        }
    }
    cout << dp[0][n][h];
}