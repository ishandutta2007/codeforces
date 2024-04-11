#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
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
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
ll a[N],dp[N][2];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,q;
        cin >> n >> q;
        rep (i,0,n){
            cin >> a[i];
        }
        dp[0][1] = a[0];
        dp[0][0] = 0;
        rep (i,1,n){
            dp[i][1] = max(dp[i-1][0]+a[i],dp[i-1][1]);
            dp[i][0] = max(dp[i-1][1]-a[i],dp[i-1][0]);
        }
        cout << max(dp[n-1][1],dp[n-1][0]) << endl;
    }
    return 0;

}