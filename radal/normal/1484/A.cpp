#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int dp[N][N];
int main(){
    int T;
    cin >> T;
    rep(i,1,N){
        dp[1][i] = i;
        dp[i][1] = i;
        if (i > 1){
            dp[2][i] = i*2;
            dp[i][2] = 2*i;
        }
    }
    rep(i,3,N){
        rep(j,3,N){
            dp[i][j] = dp[i-2][j-2]+2*i+2*j-4;
        }
    }
    while (T--){
        int a,b;
        cin >> a >> b;
        cout  << dp[a][b] << endl;;
    }
    return 0;
}