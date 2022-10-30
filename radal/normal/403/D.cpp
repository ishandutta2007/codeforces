#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll unsigned long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e3+20,inf = 1e10,mod=1e9+7;
long int dp[55][N][N]; ll C[N][N];
void mkay(ll& a){
    if (a >= mod) a-=mod;
    if (a<0) a+=mod;
}
int mult(int a,int b){
    return 1ll *a*b % mod;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(); cout.tie();
    int T;
    cin >> T;
    rep (i,0,N) C[0][i] = 1;
    rep(i,1,N){
        rep(j,i,N){
            mkay(C[i][j] = C[i-1][j-1]+C[i][j-1]);
        }
        dp[0][0][i] = 1;
        dp[1][0][i] = 1;
    }
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    rep(i,1,50){
        int l=i*(i-1)/2;
        rep(j,l,N){
            int s = sqrt(2*j);
            if (s*s == 2*j) s--;
            rep(k,s,N){
                if (j-k >= 0) {
                    dp[i][j][k] = dp[i][j][k-1] + mult(dp[i-1][j-k][k-1],i);
                    dp[i][j][k] %= mod;
                 //   dp[i][j][k] *= F[i];
                }
                else dp[i][j][k] = dp[i][j][k-1];
            }
        }
    }
    while (T--){
        ll n,m;
        cin >> n >> m;
        if (m*(m-1)/2+m > n){
            cout << 0 << endl;
            continue;
        }
        /*F[0] = 1;
        F[1] = 1;
        rep(i,2,n+1){
            F[i] = F[i-1]*i;
            F[i] %= mod;
        }*/
        if (m == 1){
            cout << n*(n+1)/2 << endl;
            continue;
        }
        //n = n-m+1;
        ll ans=0;
        rep(j,0,n){
            ans += dp[m][j][n] * C[m][n-j];
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}