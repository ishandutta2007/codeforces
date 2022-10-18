#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<vector<pll>> a(n);
	FOR(i,0,n) {
		ll k; cin >> k;
		a[i].resize(k);
		vector<pll> v(k);
		FOR(j,0,k) cin >> v[j].xx >> v[j].yy;
		FOR(j,0,k) {
			pll p = v[j], q = v[(j+1)%k];
			ll dx = q.xx-p.xx, dy = q.yy-p.yy;
			ll g = __gcd(abs(dx),abs(dy));
			dx /= g, dy /= g;
			a[i][j] = {dx,dy};
		}
	}
	
	map<pll,ll> next_index;
	vvl seg(2*n);
	
	FORD(i,0,n) {
		seg[n+i].reserve(sz(a[i]));
		for (pll v: a[i]) {
			ll j = next_index.count(v) ? next_index[v] : n;
			seg[n+i].pb(j);
			next_index[v] = i;
		}
		sort(all(seg[n+i]));
	}
	
	FORD(i,1,n) {
		vl &v = seg[2*i];
		vl &w = seg[2*i+1];
		seg[i].reserve(sz(v) + sz(w));
		merge(all(v),all(w),std::back_inserter(seg[i]));
	}
	
	auto count_above = [](const vl &v, ll x) {
		//for (ll y: v) cout << y << " " ;
		//cout << endl;
		auto it = lower_bound(all(v),x);
		return end(v)-it;
	};

	ll q; cin >> q;
	while (q--) {
		ll i, j;
		cin >> i >> j;
		i--;
		ll res = 0, x = j;
		i += n, j += n;
		for (; i < j; i /= 2, j /= 2) {
			if (i&1) res += count_above(seg[i], x), i++;
			if (j&1) j--, res += count_above(seg[j], x);
		}
		cout << res << "\n";
	}
}