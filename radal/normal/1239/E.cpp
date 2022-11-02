#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr ll N = 1300000,mod = 1e9+7,inf = 1e9+10;
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
int n;
int a[60];
int dp[N][60];
bool mark[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    int nn = 2*n;
    rep(i,1,nn+1) cin >> a[i];
    sort(a+1,a+nn+1);
    int s = 0;
    repr(i,nn,n+2) s += a[i];
    dp[0][0] = 1;
    rep(i,3,nn+1){
        repr(j,s,a[i]){
            repr(k,n-1,1){
                if (dp[j][k] == -1 && dp[j-a[i]][k-1] != -1)
                    dp[j][k] = i;
            }
        }
    }
    int s2 = s;
    rep(i,3,n+2) s += a[i];
    int j = -1,mi = inf;
    rep(i,0,s2+1){
        if (dp[i][n-1] != -1 && mi > abs(2*i-s)){
            mi = abs(2*i-s);
            j = i;
        }
    }
    vector<int> v1,v2;
    int t = n-1;
    while (t--){
        int k = dp[j][t+1];
        v1.pb(a[k]);
        j = j-a[k];
        mark[k] = 1;
    }
    rep(i,3,nn+1) if (!mark[i]) v2.pb(-a[i]);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout << a[1] << ' ';
    for (int u : v1) cout << u << ' ';
    cout << endl;
    for (int u : v2) cout << -u << ' ';
    cout << a[2];
}