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
constexpr int N = 2e2+15,mod = 998244353,inf = 1e9+10;
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

int a[N];
bool dp[N][N][2][2];
inline void solve(){
    int n,e = 0,o = 0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        if (a[i]%2) o++;
        else e++;
    }
    dp[0][0][0][0] = dp[0][0][0][1] = 1;
    rep(i,0,e+1){
        rep(j,0,o+1){
            if (i == 0 && j == 0) continue;
            rep(k,0,2){
                if (i == 0){
                    dp[i][j][k][0] = dp[i][j-1][1-k][1];
                    dp[i][j][k][1] = dp[i][j-1][k][0];
                    continue;
                }
                if (j == 0){
                    dp[i][j][k][0] = dp[i-1][j][k][1];
                    dp[i][j][k][1] = dp[i-1][j][k][0];
                    continue;
                }
                dp[i][j][k][0] = (dp[i-1][j][k][1]|dp[i][j-1][1-k][1]);
                dp[i][j][k][1] = (dp[i-1][j][k][0]&dp[i][j-1][k][0]);
            }
        }
    }
    if (dp[e][o][0][0]) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}