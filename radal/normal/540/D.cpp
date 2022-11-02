#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e2+10,mod = 998244353,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
ld dp[N][N][N][3];
int main(){
    ios :: sync_with_stdio(0);
    int a,b,c;
    cin >> a >> b >> c;
    rep(i,1,N){
        dp[i][0][0][0] = 1;
        dp[i][0][0][1] = 0;
        dp[i][0][0][2] = 0;
        dp[0][i][0][0] = 0;
        dp[0][i][0][1] = 1;
        dp[0][i][0][2] = 0;
        dp[0][0][i][0] = 0;
        dp[0][0][i][1] = 0;
        dp[0][0][i][2] = 1;
    }
    rep(i,1,N){
        rep(j,1,N){
            dp[0][i][j][0] = 0;
            dp[0][i][j][1] = 1;
            dp[0][i][j][2] = 0;
            dp[i][0][j][0] = 0;
            dp[i][0][j][1] = 0;
            dp[i][0][j][2] = 1;
            dp[i][j][0][0] = 1;
            dp[i][j][0][1] = 0;
            dp[i][j][0][2] = 0;
        }
    }
    rep(i,1,N){
        rep(j,1,N){
            rep(k,1,N){
                ll p = (i+j+k)*(i+j+k-1)/2;
                dp[i][j][k][0] = (dp[i][j-1][k][0]*i*j+dp[i-1][j][k][0]*i*k+dp[i][j][k-1][0]*j*k)/(p-i*(i-1)/2-j*(j-1)/2-k*(k-1)/2);
                dp[i][j][k][1] = (dp[i][j-1][k][1]*i*j+dp[i-1][j][k][1]*i*k+dp[i][j][k-1][1]*j*k)/(p-i*(i-1)/2-j*(j-1)/2-k*(k-1)/2);
                dp[i][j][k][2] = (dp[i][j-1][k][2]*i*j+dp[i-1][j][k][2]*i*k+dp[i][j][k-1][2]*j*k)/(p-i*(i-1)/2-j*(j-1)/2-k*(k-1)/2);
            }
        }
    }
    int f=2,d=2,e=1;
    cout << fixed << setprecision(10);
    cout << dp[a][b][c][0] << ' ' << dp[a][b][c][1] << ' ' << dp[a][b][c][2];
    return 0;
}