#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 5e3+20,mod = 1e9+7,inf = 1e9+10,base = 233;
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
int n,dp[N][N],sm[30];
string s;
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   cin >> n >> s;
   rep(i,0,n+1) dp[i][0] = 1;
   rep(j,1,n+1){
       rep(i,0,30) sm[i] = 0;
       rep(i,1,n+1){
           int c = s[i-1]-'a',cal = mkay(dp[i-1][j],-sm[c]);
           dp[i][j] = mkay(dp[i][j-1],cal);
           sm[c] = dp[i][j-1];
       }
   }
   cout << dp[n][n];
   return 0;
}