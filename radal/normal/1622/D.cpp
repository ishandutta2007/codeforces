#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 1e5+20,mod = 998244353,inf = 1e9+10,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int pre[N][2],l[N];
int dp[N],fac[N],inv[N];
inline int c(int r,int n){
    if (r < 0 || r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
   // cin >> T;
    while(T--){
        int n,k;
        string a;
        cin >> n >> k >> a;
        a = '*'+a;
        if (!k){
            cout << 1;
            return 0;
        }
        fac[0] = 1;
        inv[0] = 1;
        rep(i,1,n+1){
            pre[i][0] = (a[i] == '0');
            pre[i][1] = 1-pre[i][0];
            pre[i][0] += pre[i-1][0];
            pre[i][1] += pre[i-1][1];
            fac[i] = 1ll*i*fac[i-1]%mod;
            inv[i] = poww(fac[i],mod-2);
        }
        l[1] = 1;
        int cnt = (a[1] == '1');
        int L = 1;
        rep(i,2,n+1){
            cnt += (a[i] == '1');
            while (cnt > k){
                cnt -= (a[L] == '1');
                L++;
            }
            l[i] = L;
        }
        int j = 1;
        dp[0] = 1;
        while (j <= n && pre[j][1] < k){
            dp[j] = 1;
            j++;
        }
        rep(i,j,n+1){
            int g = c(k-(a[i] == '0'),i-l[i]);
            if (pre[i-1][1] >= k)
                dp[i] = mkay(g,dp[i-1]);
            else{
                int x = c(k-(a[i] == '1'),i-l[i]);
                dp[i] = mkay(g,x);
            }
        }
        cout << dp[n] << endl;
    }
}