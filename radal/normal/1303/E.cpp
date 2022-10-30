#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 400+10,mod = 1e9+7,inf = 1e9,sq = 65,fx = 98765431;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int dp[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,t;
        cin >> s >> t;
        int n,m;
        bool f = 0;
        n = s.size();
        m = t.size();
        rep(i,0,m){
            memset(dp,128,sizeof dp);
            if (s[0] == t[0]) dp[0][1] = 0;
            if (i < m-1 && s[0] == t[i+1]) dp[0][0] = 1;
            else dp[0][0] = 0;
            rep(j,1,n){
                rep(k,0,i+2){
                    if (!k){
                        dp[j][0] = dp[j-1][0];
                        if (dp[j-1][0]+i < m-1 && t[i+dp[j-1][0]+1] == s[j]) dp[j][0]++;
                        continue;
                    }
                    if (s[j] == t[k-1]) dp[j][k] = dp[j-1][k-1];
                    if (dp[j-1][k] >= 0 && dp[j-1][k]+i < m-1 && t[i+dp[j-1][k]+1] == s[j]) dp[j][k] = max(dp[j][k],dp[j-1][k]+1);
                    else dp[j][k] = max(dp[j][k],dp[j-1][k]);
                }
            }
            if (dp[n-1][i+1] == m-i-1){
                cout << "YES" << endl;
                f = 1;
                break;
            }
        }
        if (!f) cout << "NO" << endl;
    }
}