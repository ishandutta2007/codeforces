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
#define DBG if(0)

const int V = (1<<24);
const int mod = 31607;

ll ipow(ll b, ll e, ll mod) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		(b *= b) %= mod; e /= 2;
	}
	return ret;
}

int n;
int a[21][21];
int ai[21][21];
int rp[21];
int ans;

void DoRow() {
	rep(i, n) {
		rp[i] = 1;
		rep(j, n) rp[i] = rp[i] * a[i][j] % mod;
	}

	int t = 1;
	rep(i, n) {
		int x = mod + 1 - rp[i];
		if (x >= mod) x -= mod;
		t = (t * x) % mod;
	}

	ans = (mod + 1 - t);
	if (ans >= mod) ans = mod;
}

int marks[21][21];

int co = 1;
int rv[21];

void Upd(int r, int c, int d) {
	if (!marks[r][c]) {
		rv[r] = rv[r] * ai[r][c] % mod;
		co *= a[r][c]; co %= mod;
	}
	marks[r][c] += d;
	if (!marks[r][c]) {
		rv[r] = rv[r] * a[r][c] % mod;
		co *= ai[r][c];
		co %= mod;
	}
}

int main()
{
	cppio();

	cin >> n;
	rep(i, n) rep(j, n) {
		cin >> a[i][j];
		a[i][j] = a[i][j] * 3973 % mod;
		ai[i][j] = ipow(a[i][j], mod-2, mod);
	}

	DoRow();
	copy(rp, rp+n, rv);

	for (int mask=1; mask<(1<<(n+2)); ++mask) {
		int lbv = (mask&(-mask));
		int lb = 0;
		while (lbv != (1<<lb)) ++lb;

		auto Work = [&](int bit, int sgn) {
			if (bit == 0) rep(j, n) Upd(j, j, sgn);
			else if (bit == 1) rep(j, n) Upd(j, n-1-j, sgn);
			else rep(j, n) Upd(j, bit-2, sgn);
		};

		rep(i, lb) Work(i, -1);
		Work(lb, +1);

		int t = co;
		rep(i, n) t = t * (mod+1-rv[i]) % mod;
		if (1&(__builtin_popcount(mask))) {
		} else if (t) t = mod-t;
		ans += t; if (ans >= mod) ans -= mod;
	}

	cout << ans << '\n';

	return 0;
}