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

#define norm asdf

set<ll> L = {0}, R, norm, spec;
ll sumL = 0, sumR = 0, k = 0;

void adjust() {
	while (sz(R) < k) {
		ll x = *rbegin(L);
		L.erase(x), R.insert(x);
		sumL -= x, sumR += x;
	}
	while (sz(R) > k) {
		ll x = *begin(R);
		L.insert(x), R.erase(x);
		sumL += x, sumR -= x;
	}
}

void add(ll x, ll t) {
	if (x > *rbegin(L)) R.insert(x), sumR += x;
	else L.insert(x), sumL += x;
	(t ? spec : norm).insert(x);
	adjust();
}

void del(ll x, ll t) {
	if (L.count(x)) L.erase(x), sumL -= x;
	else R.erase(x), sumR -= x;
	(t ? spec : norm).erase(x);
	adjust();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	L.insert(0);
	norm.insert(0);

	ll n; cin >> n;
	while (n--) {
		ll t, d;
		cin >> t >> d;
		
		if (d > 0) {
			k += t;
			add(d,t);
		} else {
			k -= t;
			del(-d,t);
		}

		ll cur = sumL + 2*sumR;
		if (k > 0 && *rbegin(norm) < *begin(R)) {
			cur -= *begin(R);
			cur += *rbegin(norm);
		}
		cout << cur << '\n';
	}
}