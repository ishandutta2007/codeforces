#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 4e3+20,mod = 1e9+7,inf = 1e9+10;
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

ll dp[2][2][N][N],pr[N];
int a[N];
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        pr[i] = pr[i-1]+a[i];
    }
    int lim = 64;
    repr(k,lim-1,1){
        int d = (k&1);
        int calc = ((k*k-1) >> 2),lm = n-calc+2;
        repr(l,lm-k-1,1){
            if (l < calc) break;
            dp[0][d][l][l+k] = pr[l+k-1]-pr[l-1];
            dp[1][d][l][l+k] = pr[l-1]-pr[l+k-1];
            rep(r,l+k+1,lm){
                ll s1,s2;
                s1 = pr[l+k-1]+dp[1][d][l+k][r];
                s2 = pr[l+k]+dp[1][1-d][l+k+1][r];
                dp[0][d][l][r] = max(s1,s2)-pr[l-1];
                s1 = pr[r-k-1]+dp[0][d][l][r-k];
                s2 = pr[r-k-2]+dp[0][1-d][l][r-k-1];
                dp[1][d][l][r] = min(s1,s2)-pr[r-1];
            }
        }
    }
    cout << dp[0][1][1][n+1];
    return 0;
}