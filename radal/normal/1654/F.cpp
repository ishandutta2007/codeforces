#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
typedef pair<ll,ll> pll;
constexpr int N = 1e6+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int dp[N][20];
pll r[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int m = (1 << n);
    rep(i,0,m){
        dp[i][0] = s[i]-'a';
    }
    rep(j,1,n+1){
        vector<pll> ve;
        rep(i,0,m){
            r[i] = {dp[i][j-1],dp[i^(1 << (j-1))][j-1]};
            ve.pb(r[i]);
        }
        sort(ve.begin(),ve.end());
        rep(i,0,m)
            dp[i][j] = lower_bound(ve.begin(),ve.end(),r[i])-ve.begin();
    }
    rep(i,0,m){
        if (!dp[i][n]){
            string t;
            t.resize(m);
            rep(j,0,m){
                t[j] = s[(j^i)];
            }
            cout << t;
            return 0;
        }
    }
}