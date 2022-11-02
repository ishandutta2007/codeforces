#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(int a,int k){
    if (k == 1) return a;
    if (!k) return 1;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
ll dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        int v = poww(2,n-1);
        if (n&1){
            dp[0] = 1;
            rep(i,1,k+1){
                dp[i] = dp[i-1]+(v*dp[i-1])%mod;
                dp[i] %= mod;
            }
            cout << dp[k] << endl;
        }
        else{
            dp[0] = 1;
            rep(i,1,k+1){
                dp[i] = poww(poww(2,i-1),n);
                dp[i] += (dp[i-1]*(v-1))%mod;
                dp[i] %= mod;
            }
            cout << dp[k] << endl;
        }
    }
    return 0;
}