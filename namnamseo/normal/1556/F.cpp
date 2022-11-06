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

const int maxn = int(2e5) + 10;
const int mod = int(1e9) + 7;

int n, am;
int a[maxn];

int pow3[20];
ll ipow(ll b, ll e, ll mod) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}
ll modinv(ll x) { return ipow(x, mod-2, mod); }
ll win(int f, int t) { return (a[t]) * modinv(a[f]+a[t]) % mod; }
ll wins[1<<14][14];
ll cyc[1<<14];
ll Winp(ll m, ll om) {
	ll ret = 1;
	while (om) {
		int i = __builtin_ctz(om);
		(ret *= wins[m][i]) %= mod;
		om &= (om-1);
	}
	return ret;
}

void Build() {
	pow3[0] = 1;
	rrep(i, n) pow3[i] = pow3[i-1] * 3;
	am = (1<<n)-1;
	fill(wins[0], wins[0]+n, 1ll);
	for (int m=1; m<=am; ++m) {
		int i = __builtin_ctz(m);
		int bm = (m&(m-1));
		rep(j, n) wins[m][j] = wins[bm][j] * win(j, i) % mod;
	}
	for (int m=1; m<=am; ++m) {
		ll nc = 0;
		for (int wm=(m&(m-1)); wm; wm=((wm-1)&m)) {
			nc += Winp(wm, m^wm) * cyc[wm] % mod;
			if (nc >= mod) nc -= mod;
		}
		nc = mod+1-nc;
		while (nc >= mod) nc -= mod;
		cyc[m] = nc;
	}
}

int main()
{
	cppio();
	cin >> n;
	rep(i, n) cin >> a[i];

	Build();

	ll ans = 0;

for (int m=1; m<=am; ++m) {
	ll winp = Winp(m, am^m);
	ll cycp = cyc[m];
	ans += winp * cycp % mod * (int(__builtin_popcount(m))) % mod;
	if (ans >= mod) ans -= mod;
}

	cout << ans << '\n';

	return 0;
}