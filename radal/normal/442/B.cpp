#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e5+10,mod = 998244353,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
ld a[N];
ld dp[N][2];
int main(){
    ios :: sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    dp[n-1][0] = 1-a[n-1];
    dp[n-1][1] = a[n-1];
    ld mx = a[n-1];
    repr(i,n-2,0){
        dp[i][0] = dp[i+1][0]*(1-a[i]);
        dp[i][1] = dp[i+1][1]*(1-a[i])+dp[i+1][0]*a[i];
        mx = max(mx,dp[i][1]);
    }
    cout << fixed << setprecision(10) <<mx;
    return 0;
}