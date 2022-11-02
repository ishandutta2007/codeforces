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
typedef pair<int,int> pll;
const long long int N=2e3+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll a[N];
ll dp[N][N];
int main(){
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    sort(a+1,a+n+1);
    dp[0][0] = 0;
    rep(i,1,n+1) dp[i][i] = 0;
    repr(l,n-1,1){
        rep(r,l+1,n+1){
            dp[l][r] = min(dp[l+1][r],dp[l][r-1])+a[r]-a[l];
        }
    }
    cout << dp[1][n];
    return 0;
}