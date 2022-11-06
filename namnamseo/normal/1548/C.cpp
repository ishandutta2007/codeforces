#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(1e6) + 10;
const int maxn3 = int(3e6) + 10;
const int mod = int(1e9) + 7;

ll ipow(ll b, ll e, ll mod) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}

int n, q;

int fact[maxn3];
int finv[maxn3];

int B[maxn3];

int C(int n, int r) {
	if (r < 0 || r > n) return 0;
	return fact[n] * 1ll * finv[r] % mod * finv[n-r] % mod;
}

void Build() {
	{
	const int T = 3*n + 5;
	fact[0] = 1;
	for (int i=1; i<=T; ++i) fact[i] = (fact[i-1]*1ll*i)%mod;
	finv[T] = ipow(fact[T], mod-2, mod);
	for (int i=T; 1<=i; --i) finv[i-1] = (finv[i]*1ll*i)%mod;
	}

	static int Co[maxn3];
	for (int i=1; i<=3*(n+1); ++i) {
		Co[i-1] = C(3*(n+1), i);
	}

	for (int i=3*(n+1); i>=2; --i) {
		ll a = Co[i];
		B[i-2] = a;
		a *= 3; a %= mod;
		Co[i-1] = (Co[i-1] + mod-a) % mod;
		Co[i-2] = (Co[i-2] + mod-a) % mod;
	}
}

int main()
{
	cppio();
	cin >> n >> q;

	Build();
	for(;q--;) {
		int x; cin >> x;
		int ans = B[x];
		cout << ans << '\n';
	}

	return 0;
}