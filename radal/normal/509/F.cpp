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
const long long int N = 5e2+20,mod = 1e9+7,inf = 1e18,sq = 400,sig = 26;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int dp[N][N],a[N],sum[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        dp[i][i+1] = 1;
        sum[i][i] = 1;
    }
    sum[n][n] = 1;
    repr(l,n-2,0){
        rep(r,l+2,n+1){
            rep(i,l+1,r)
                if(i+1 >= r || a[i+1] >= a[l+1]) sum[l+1][r] = mkay(sum[l+1][r],1ll*sum[i+1][r]*dp[l+1][i+1]%mod);
            dp[l][r] = sum[l+1][r];
        }
    }
    cout << dp[0][n];
}