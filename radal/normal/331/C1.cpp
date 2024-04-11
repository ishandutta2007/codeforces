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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e9+7,inf=1e12,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    dp[0] = 0;
    rep(i,1,n+1){
        dp[i] = inf;
        int k = i;
        vector <short int> ve;
        while(k){
            ve.pb(k%10);
            k/=10;
        }
        for (int u : ve) dp[i] = min(dp[i],dp[i-u]+1);
    }
    cout << dp[n];
    return 0;
}