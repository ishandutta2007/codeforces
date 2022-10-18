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

char convert(ll x) {
	if (x < 26) return 'A' + x;
	if (x < 52) return 'a' + (x-26);
	return '0' + (x-52);
}

void solve() {
	ll m, n, k;
	cin >> m >> n >> k;

	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];

	ll s = 0;
	FOR(i,0,m) FOR(j,0,n) s += a[i][j] == 'R';

	vl c(k);
	FOR(i,0,s) c[i%k]++;
	
	ll t = 0;
	vvl res(m,vl(n));
	FOR(i,0,m) {
		auto [jmin,jmax,dj] = i%2 ? make_tuple(0LL,n-1,1) : make_tuple(n-1,0LL,-1);
		for (ll j = jmin; ; j += dj) {
//			cout << i << " " << j << endl;
			res[i][j] = t;
			c[t] -= a[i][j] == 'R';
			if (c[t] == 0 && t < k-1) t++;
			if (j == jmax) break;
		}
	}
	
	FOR(i,0,m) FOR(j,0,n) {
		cout << convert(res[i][j]);
		if (j+1 == n) cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}