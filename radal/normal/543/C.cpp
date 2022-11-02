#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 2e6+20,mod = 1e9+7,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
int sm[N][22],dp[N],ct[N];
int a[22][22],bt[22][30],mx[22][30];
string s[22];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(dp,63,sizeof dp);
    int n,m;
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    rep(j,0,n){
        rep(i,0,m){
            cin >> a[j][i];
            int c = s[j][i]-'a';
            bt[i][c] |= (1 << j);
            mx[i][c] = max(a[j][i],mx[i][c]);
        }
    }
    int y = (1 << n);
    rep(i,1,y) ct[i] = __builtin_ctz(i);
    rep(j,0,m){
        sm[0][j] = 0;
        rep(i,1,y)
            sm[i][j] = a[ct[i]][j]+sm[i^(i&(-i))][j];
    }
    dp[0] = 0;
    rep(i,1,y){
        int ind = ct[i],id = (i&(-i));
        rep(j,0,m){
            dp[i] = min(dp[i],dp[i-id]+a[ind][j]);
            int c = s[ind][j]-'a';
            int b = bt[j][c],x = (b&i);
            dp[i] = min(dp[i],dp[i^x]+sm[b][j]-mx[j][c]);
        }
    }
    cout << dp[y-1];
}