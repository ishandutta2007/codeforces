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
typedef pair<int,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b& 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll h[N];
pll dp[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k,sum = 0;
        cin >> n >> k;
        bool f = 0;
        rep(i,0,n){
            cin >> h[i];
        }
        dp[0] = {h[0],h[0]};
        rep(i,1,n){
            dp[i].X = max(dp[i-1].X-k+1,h[i]);
            dp[i].Y = min(dp[i-1].Y+k-1,h[i]+k-1);
            if (dp[i].X > h[i]+k-1 || dp[i].Y < h[i]) f = 1;
        }
        if (f || dp[n-1].X > h[n-1] || dp[n-1].Y < h[n-1]) cout << "NO" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}