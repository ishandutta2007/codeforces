#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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

int dp[N][2];
string s[2];
void solve(){
    int n;
    cin >> n >> s[0] >> s[1];
    repr(i,n-2,0){
        if (s[1][i] == '1'){
            if (s[0][i+1] == '0')
                dp[i][0] = min(dp[i+1][1],dp[i+1][0]+1);
            else
                dp[i][0] = 1+min(dp[i+1][0],dp[i+2][1]);
        }
        else
            dp[i][0] = dp[i+1][0];
        if (s[0][i] == '1'){
            if (s[1][i+1] == '0')
                dp[i][1] = min(dp[i+1][0],dp[i+1][1]+1);
            else
                dp[i][1] = 1+min(dp[i+1][1],dp[i+2][0]);
        }
        else
            dp[i][1] = dp[i+1][1];
    }
    int ans = -dp[0][0];
    rep(i,0,n) ans += s[0][i]+s[1][i]-2*'0';
    cout << ans;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    while (T--){
        solve();
    }
    return 0;
}