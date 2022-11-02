#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e3+20,mod = 1e9+7,inf = 1e18+10,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int n,m,k;
int dp[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    int inv = poww(2,mod-2);
    while (T--){
        cin >> n >> m >> k;
        rep(i,1,n+1){
            dp[i][i] = 1ll*k*i%mod;
        }
        rep(i,1,n+1){
            rep(j,1,i){
                dp[i][j] = 1ll*mkay(dp[i-1][j],dp[i-1][j-1])*inv%mod;
            }
        }
        cout << dp[n][m] << endl;
    }
}