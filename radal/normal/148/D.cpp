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
const long long int N=1e3+10,mod = 998244353,inf=4e18,maxm = 1000;
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
ld dp[N][N][2];
int main(){
    ios :: sync_with_stdio(0);
    int a,b;
    cin >> a >> b;
    if (a == 0){
        cout << 0;
        return 0;
    }
    if (b == 0){
        cout << 1;
        return 0;
    }
    rep(i,1,N){
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
    }
    rep(i,1,N){
        rep(j,1,N){
            dp[i][j][0] = 1.0*i/(i+j)+1.0*j/(i+j)*dp[i][j-1][1];
            if (j > 1) dp[i][j][1] = 1.0*j/(i+j)*(1.0*i/(i+j-1)*dp[i-1][j-1][0]+1.0*(j-1)/(i+j-1)*dp[i][j-2][0]);
            else dp[i][j][1] = 1.0*j/(i+j)*(i/(i+j-1)*dp[i-1][j-1][0]);
        }
    }
    cout << fixed << setprecision(10) << dp[a][b][0];
    return 0;
}