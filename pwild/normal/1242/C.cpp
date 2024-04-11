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

void fail() {
	cout << "No" << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl sum(n);
	vvl a(n);
	map<ll,ll> where;
	FOR(i,0,n) {
		ll m; cin >> m;
		a[i].resize(m);
		for (ll &x: a[i]) {
			cin >> x;
			where[x] = i;
		}
		sum[i] = accumulate(all(a[i]),0LL);
	}
	
	ll total = accumulate(all(sum),0LL);
	if (total % n) fail();
	total /= n;
	
	vector<pll> take(1 << n,mp(-1,-1));

	FOR(k,0,n) for (ll x: a[k]) {
		ll i = k, y = x, mask = 0;
		bool ok = true;
		do {
			// sum[i] - y + z == total
			ll z = total-sum[i] + y;
			if (!where.count(z) || (mask & (1 << i))) {
				ok = false;
				break;
			}
			mask |= 1 << i;
			i = where[z], y = z;
		} while (i != k);
		if (x != y) ok = false;
		if (ok) {
			take[mask] = {i,x};
			// cout << mask << " " << i << " " << x << endl;
		}
	}
	
	vl pred(1 << n,-1);
	pred[0] = 0;
	FOR(mask,1,1 << n) for (ll smask = mask; smask; smask = (smask-1) & mask) {
		if (take[smask].xx == -1 || pred[mask^smask] == -1) continue;
		pred[mask] = smask;
	}

	ll mask = (1 << n) - 1;
	if (pred[mask] == -1) fail();

	vector<pll> res(n);
	for (; mask; mask ^= pred[mask]) {
		ll k, x;
		tie(k,x) = take[pred[mask]];
		ll i = k, y = x;
		do {
			// sum[i] - y + z == total
			ll z = total-sum[i] + y;
			ll j = where[z];
			res[j] = {z,i};
			i = j, y = z;
		} while (i != k);
	}

	cout << "Yes" << endl;
	FOR(i,0,n) cout << res[i].xx << " " << res[i].yy+1 << endl;
}