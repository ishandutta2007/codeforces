#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 6e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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

int fac[N],inv[N],dp[N];

int c(int r,int n){
	if (r > n || r < 0) return 0;
	return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}

void solve(){
	int n;
	cin >> n;
	int ans = 0,o = 1,pw = 1;
	rep(i,0,n+1){
		if (4*i > n) break;
		int z = 2*i;
		int cal = 1ll*dp[n-4*i]*o%mod;
		cal = 1ll*cal*c(z,n-z)%mod*pw%mod;
		o = 1ll*o*(2*i+1)%mod;
		ans = mkay(ans,cal);
		pw = mkay(pw,pw);
	}
	cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	fac[0] = inv[0] = 1;
	dp[0] = 1;
	dp[1] = 1;
	rep(i,1,N){
		fac[i] = 1ll*i*fac[i-1]%mod;
		inv[i] = poww(fac[i],mod-2);
	}
	rep(i,2,N){
		dp[i] = mkay(dp[i-1],1ll*dp[i-2]*(i-1)%mod);
	}
	while (T--){
		solve();
	}
    return 0;
}