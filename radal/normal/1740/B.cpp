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
constexpr int N = 1e6+15,mod = 998244353,inf = 1e9+10;
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

pll a[N];
vector<pll> ve;
vector<int> val;
void solve(){
	int n;
	cin >> n;
	ll s = 0;
	int mx = 0;
	ve.clear();
	val.clear();
	rep(i,0,n){
		cin >> a[i].X >> a[i].Y;
		if (a[i].X < a[i].Y) swap(a[i].X,a[i].Y);
		val.pb(a[i].X);
		val.pb(a[i].Y);
		ve.pb({a[i].X,a[i].Y});
		s += a[i].X;
		mx = max(mx,a[i].Y);
	}
	sort(all(val));
	sort(all(ve));
	ll ans = 1ll*inf*inf;
	int p = 0;
	for (int v : val){
		if (v < mx) continue;
		while (p < n && ve[p].X <= v){
			s -= ve[p].X;
			s += ve[p].Y;
			p++;
		}
		ans = min(ans,2*(s+v));
	}
	cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
    return 0;
}