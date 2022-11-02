#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10,base = 233;
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
vector<vector<int> > dp;
bool good[N];
int pw[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size(),hsh = 0,hsh2 = 0;
    dp.resize(n);
    rep(i,0,n) dp[i].resize(m+1);
    rep(i,1,m+1) dp[0][i] = -inf;
    pw[0] = 1;
    rep(i,1,m+1) pw[i] = 1ll*base*pw[i-1]%mod;
    good[0] = 1;
    rep(i,0,m){
        hsh = (1ll*hsh*base+t[i]-'a'+1)%mod;
        hsh2 = mkay(hsh2,1ll*pw[i]*(t[m-i-1]-'a'+1)%mod);
        if (hsh == hsh2) good[i+1] = 1;
    }
    dp[0][0] = 0;
    if (s[0] == '?' || s[0] == t[0]){
        dp[0][1] = 0;
        if ((int)t.size() == 1) dp[0][1] = 1;
    }
    rep(i,1,n){
        rep(j,0,m+1){
            if (!j){
                dp[i][j] = max(dp[i-1][0],dp[i-1][m]);
                continue;
            }
            if (s[i] != '?' && s[i] != t[j-1]){
                dp[i][j] = -inf;
                continue;
            }
            if (j == 1){
                dp[i][j] = max(dp[i-1][0],dp[i-1][m]);
                if (j == m) dp[i][j]++;
                continue;
            }
            if (good[j-1]){
                dp[i][j] = max(dp[i-1][m],dp[i-1][j-1]);
                if (j == m) dp[i][j]++;
                continue;
            }
            dp[i][j] = dp[i-1][j-1];
            if (j == m) dp[i][j]++;
            continue;
        }
    }
    cout << max(dp[n-1][0],dp[n-1][m]);
}