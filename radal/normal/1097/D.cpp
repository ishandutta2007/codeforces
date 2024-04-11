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
const long long int N = 1e4+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
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
int dp[60][60][N],inv[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll n;
    int k;
    cin >> n >> k;
    if (n == 1){
        cout << 1;
        return 0;
    }
    rep(i,0,60){
        dp[i][i][0] = 1;
    }
    rep(i,1,60+1){
        inv[i] = poww(i,mod-2);
    }
    rep(i,0,50)
        repr(j,i,0)
            rep(x,1,k+1)
                rep(y,j,i+1)
                    dp[i][j][x] = mkay(dp[i][j][x],1ll*dp[i][y][x-1]*inv[y+1]%mod);

    vector<pair<ll,int>> ve;
    vector<ll> ve2;
    ll n2 = n;
    ve2.pb(n);
    ve2.pb(1);
    rep(i,2,sq){
        if (n2%i == 0){
            if(n2/i > i){
                ve2.pb(i);
                ve2.pb(n2/i);
            }
            if (i == n2/i){
                ve2.pb(i);
            }
        }
        int t = 0;
        while (n%i == 0){
            n /= i;
            t++;
        }
        if (t) ve.pb({i,t});
    }
    if (n > 1) ve.pb({n,1});
    int ans = 0;
    for (ll u : ve2){
        ll v = u; 
        int r = 1;
        for (auto p : ve){
            int cnt = 0;
            while (v%p.X == 0){
                cnt++;
                v /= p.X;
            }
            r = 1ll*r*dp[p.Y][cnt][k]%mod;
        }
        ans = mkay(ans,1ll*u%mod*r%mod);
    }
    cout << ans;

}