#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 3e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int a[N];
int dp[10][N],mark[N];
int cnt[N],fac[N],inv[N];
vector<int> taj[N];
inline int c(int r,int n){
    if (r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,g = 0;
    cin >> n;
    fac[0] = 1;
    inv[0] = 1;
    rep(i,0,n){
        cin >> a[i];
        g = gcd(a[i],g);
        fac[i+1] = 1ll*(i+1)*fac[i]%mod;
        inv[i+1] = poww(fac[i+1],mod-2);
    }
    rep(i,1,N){
        for (int j = i; j < N; j += i){
            taj[j].pb(i);
        }
    }
    if (g >= 2){
        cout << -1;
        return 0;
    }
    sort(a,a+n);
    n = unique(a,a+n)-a;
    rep(i,0,n){
        for (int u : taj[a[i]])
            cnt[u]++;
    }
    rep(i,1,8){
        repr(j,N-1,1){
            dp[i][j] = c(i,cnt[j]);
            for(int k = 2*j; k < N; k += j)
                dp[i][j] = mkay(dp[i][j],-dp[i][k]);
        }
        if (dp[i][1]){
            cout << i;
            return 0;
        }
    }
    return 0;
}