#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
using vi = vector<int>;

const double pi = 2*acos(0);
#define M_PI pi

namespace FFT { // from KACTL

typedef complex<double> C;
typedef vector<double> vd;

void fft(vector<C> &a, vector<C> &rt, vi& rev, int n) {
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
	}
}

vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n), rt(n, 1); vi rev(n);
	rep(i,0,n) rev[i] = (rev[i/2] | (i&1) << L) / 2;
	for (int k = 2; k < n; k *= 2) {
		C z[] = {1, polar(1.0, M_PI / k)};
		rep(i,k,2*k) rt[i] = rt[i/2] * z[i&1];
	}
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in, rt, rev, n);
	trav(x, in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out, rt, rev, n);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4*n);
	return res;
}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, x, y;
	cin >> n >> x >> y;

	vl a(n+1);
	FOR(i,0,n+1) cin >> a[i];

	vector<double> p(x+1), q(x+1);
	FOR(i,0,n+1) p[a[i]] = 1;
	FOR(i,0,n+1) q[x-a[i]] = 1;
	
	auto r = FFT::conv(p,q);
	
	ll m = 5e5 + 5;

	vl dp(m,-1);
	FOR(i,x+1,sz(r)) if (abs(r[i]) > eps) dp[i-x+y] = i-x+y;

	FOR(i,1,m) for (ll j = 2*i; j < m; j += i) dp[j] = max(dp[j], dp[i]);

	ll tc; cin >> tc;
	while (tc--) {
		ll len; cin >> len;
		ll res = dp[len/2];
		if (res > 0) res *= 2;
		cout << res << "\n "[!!tc];
	}

}