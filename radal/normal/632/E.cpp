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
const long long int N = 1e6+20,mod = 1e9+9,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k,int m){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%m;
        n = (1ll*n*n)%m;
        k >>= 1;
    }
    return c;
}
int dp[N],a[N];
int main(){
    memset(dp,63,sizeof dp);
    int n,k;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    int x = a[0];
    repr(i,n-1,0) a[i] -= a[0];
    dp[0] = 0;
    cout << x*k << ' ';
    rep(i,1,N){
        rep(j,1,n){
            if (a[j] > i) break;
            dp[i] = min(dp[i],dp[i-a[j]]+1);
        }
        if (dp[i] <= k) cout << i+x*k << ' ';
    }

}