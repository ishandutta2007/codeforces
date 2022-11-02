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
const long long int N=2e6+20,mod = 998244353 ,inf=2e18,dlt = 12250;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
ll cnt[N],dp[N],p[N],pre[N];
int main(){
    int n;
    cin >> n;
    rep(i,1,n+1) for (int j = 1; i*j<=n; j++) cnt[i*j]++;
    dp[1] = 1;
    ll sum = 1;
    rep(i,2,n+1){
        dp[i] = sum+cnt[i];
        dp[i] %= mod;
        sum += dp[i];
        sum %= mod;
    }
    cout << dp[n];
    return 0;
}