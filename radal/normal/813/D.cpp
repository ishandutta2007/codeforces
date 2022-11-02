#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 5e3+5,mod = 1e9+7,inf = 1e9+10;
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
int mx[100000+10],cal[7],dp[N][N],a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    int ans = 0;
    rep(i,1,n+1){
        dp[i][0] = max({cal[a[i]%7],mx[a[i]-1],mx[a[i]+1]})+1;
        cal[a[i]%7] = max(cal[a[i]%7],dp[i][0]);
        mx[a[i]] = max(mx[a[i]],dp[i][0]);
        ans = max(ans,dp[i][0]);
    }
    memset(cal,0,sizeof cal);
    memset(mx,0,sizeof mx);
    rep(i,1,n+1){
        rep(j,1,n+1){
            if (i == j){
                dp[i][j] = -inf;
                continue;
            }
            if (j < i){
                dp[i][j] = dp[j][i];
                cal[a[j]%7] = max(cal[a[j]%7],dp[i][j]);
                mx[a[j]] = max(mx[a[j]],dp[i][j]);
                continue;
            }
            dp[i][j] = max({dp[i][0],cal[a[j]%7],mx[a[j]-1],mx[a[j]+1]})+1;
            cal[a[j]%7] = max(cal[a[j]%7],dp[i][j]);
            mx[a[j]] = max(mx[a[j]],dp[i][j]);
            ans = max(ans,dp[i][j]);
        }
        memset(cal,0,sizeof cal);
        rep(j,1,n+1) mx[a[j]] = 0;
    }
    cout << ans;
    return 0;
}