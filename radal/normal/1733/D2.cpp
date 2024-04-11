#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
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
constexpr int N = 5e3+15,mod = 1e9+7,inf = 1e9+10;
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
ll dp[2][N][2][2];
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    string s,t;
    cin >> s >> t;
    int cnt = 0;
    rep(i,0,n) if (s[i] != t[i]) cnt++;
    if (cnt%2){
        cout << -1 << endl;
        return;
    }
    if (y <= x){
            if (cnt != 2){
            cout << 1ll*cnt/2*y << endl;
            return;
        }
        bool fl = 0;
        rep(i,1,n){
            if ((s[i] != t[i]) && (s[i-1] != t[i-1]))
                fl = 1;
        }
        if (!fl){
            cout << y << endl;
            return;
        }
        if (2*y >= x){
            cout << x << endl;
            return;
        }
        cout << 2*y << endl;
        return;
    }
    string w;
    w.resize(n);
    rep(i,0,n){
        if (s[i] != t[i]) w[i] = '1';
        else w[i] = '0';
    }
    repr(l,n-1,0){
        int d = l%2;
        rep(r,l+1,n+1){
            if (r-l == 1){
                dp[d][r][0][0] = 0;
                dp[d][r][1][0] = 0;
                dp[d][r][0][1] = 0;
                dp[d][r][1][1] = 0;
                continue;
            }
            if (w[l] == '1'){
                dp[d][r][1][0] = dp[1-d][r][0][0];
                dp[d][r][1][1] = dp[1-d][r][0][1];
                if (w[r-1] == '0'){
                    dp[d][r][0][0] = dp[d][r-1][0][0];
                    dp[d][r][0][1] = min({dp[1-d][r][1][1]+x,dp[d][r-1][0][1]+x,dp[1-d][r-1][0][0]+y});
                }
                else{
                    dp[d][r][0][1] = dp[d][r-1][0][0];
                    dp[d][r][0][0] = min({dp[1-d][r][1][0]+x,dp[d][r-1][0][1]+x,dp[1-d][r-1][0][0]+y});
                }
            }
            else{
                dp[d][r][0][0] = dp[1-d][r][0][0];
                dp[d][r][0][1] = dp[1-d][r][0][1];
                if (w[r-1] == '0'){
                    dp[d][r][1][0] = dp[d][r-1][1][0];
                    dp[d][r][1][1] = min({dp[1-d][r][1][1]+x,dp[d][r-1][1][1]+x,dp[1-d][r-1][0][0]+y});
                }
                else{
                    dp[d][r][1][1] = dp[d][r-1][1][0];
                    dp[d][r][1][0] = min({dp[1-d][r][1][0]+x,dp[d][r-1][1][1]+x,dp[1-d][r-1][0][0]+y});
                }
            }
        }
    }
    cout << dp[0][n][0][0] << endl;
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}