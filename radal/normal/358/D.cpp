#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e3+30,mod = 1e9+7,inf=1e18;
ll dp[N][2],a[N],b[N],c[N];
int main(){
    ll n;
    cin >> n;
    rep (i,0,n) cin >> a[i];
    rep (i,0,n) cin >> b[i];
    rep (i,0,n) cin >> c[i];
    if (n == 1){
        cout << a[0];
        return 0;
    }
    if (n == 2){
        cout << max(a[0]+b[1],a[1]+b[0]);
        return 0;
    }
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    rep (i,1,n){
        dp[i][1] = max(dp[i-1][1]+b[i],dp[i-1][0]+c[i]);
        dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][0]+b[i]);
    }
   // debug(dp[n-1][1]);
    cout <<dp[n-1][0];
}