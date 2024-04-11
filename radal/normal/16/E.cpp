#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=20,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = (1 << 18)+2;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
long double a[N][N];
long double dp[N][maxm];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        rep(j,0,n) cin >> a[i][j];
        dp[i][(1 << i)] = 1;
    }
    int g = (1 << n);
    rep(i,1,g){
        int pc = __builtin_popcount(i);
        if (pc == 1) continue;
        int r = i,sz = 0;
        string s ="";
        while (r){
            sz++;
            if (r&1) s += '1';
            else s += '0';
            r >>= 1;
        }
        while (sz < n){
            s += '0';
            sz++;
        }
        rep(j,0,n){
            if (s[j] == '0') continue;
            rep(k,0,n-1){
                if (s[k] == '0') continue;
                rep(p,k+1,n){
                    if (s[p] == '0') continue;
                    if (k == j){
                        dp[j][i] += a[k][p]*dp[j][i-(1 << p)]*(2.0/pc/(pc-1));
                        continue;
                    }
                    dp[j][i] += a[p][k]*dp[j][i-(1 << k)]*(2.0/pc/(pc-1));
                    if (p == j) continue;
                    dp[j][i] += a[k][p]*dp[j][i-(1 << p)]*(2.0/pc/(pc-1));
                }
            }
        }
    }
    cout << setprecision(8) << fixed;
    rep(i,0,n) cout << dp[i][g-1] << ' ';
    return 0;
}