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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, q;
	cin >> n >> m >> q;
	vl a(n), b(m);
	FOR(i,0,n) {
		cin >> a[i];
		if (i%2 == 1) a[i] = -a[i];
	}
	FOR(i,0,m) {
		cin >> b[i];
		if (i%2 == 1) b[i] = -b[i];
	}
	
	vl bsums;
	ll cur_bsum = 0;
	FOR(i,0,n) cur_bsum += b[i];
	
	bsums.pb(cur_bsum);
	FOR(i,n,m) {
		cur_bsum += b[i] - b[i-n];
		bsums.pb((((i-n)&1) ? 1 : -1) * cur_bsum);
	}
	sort(all(bsums));
	
	ll asum = 0;
	FOR(i,0,n) asum += a[i];
	
	auto go = [&]() {
		auto it = lower_bound(all(bsums),asum);
		ll res = oo;
		if (it != end(bsums)) res = min(res,(*it)-asum);
		if (it != begin(bsums)) {
			it--;
			res = min(res,asum-(*it));
		}
		cout << res << "\n";
	};

	go();
	while (q--) {
		ll l, r, x; cin >> l >> r >> x;
		l--;
		if (l & 1) asum -= x, l++;
		if (r & 1) asum += x, r--;
		go();
	}
}