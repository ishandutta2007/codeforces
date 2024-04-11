#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e3+20,inf = 1e10,mod=1e9+7;
ll t[N],dp[N][N];
int main(){
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        rep(i,0,n) {
            cin >> t[i];
        }
        rep(i,0,n){
            rep(j,0,i+1) dp[i][j] = inf;
        }
        sort(t,t+n);
        rep(i,1,3*n) dp[0][i] = min(dp[0][i-1],abs(i-t[0]));
        rep(i,1,n){
            rep(j,i+1,3*n){
        //        debug(j);
          //      debug(dp[i][j]);
                dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(t[i]-j));
            }
        }
        cout << dp[n-1][3*n-1] << endl;
    }
}