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

void brute(ll n) {
	vl p(n);
	iota(all(p),1);

	set<vl> reach = {p};

	while (true) {
		set<vl> nreach = reach;
		for (vl p: reach) {
			FOR(i,0,n/2) {
				vl q = p;
				FOR(j,0,i) swap(q[j],q[n-i+j]);
				nreach.insert(q);
			}
		}
		if (sz(reach) == sz(nreach)) break;
		reach = nreach;
	}
	
	for (vl p: reach) {
		for (ll x: p) cout << x << " ";
		cout << endl;
	}
	cout << sz(reach) << endl;
}

bool solve() {
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];
	
	if (n%2 == 1 && a[n/2] != b[n/2]) return false;
	
	vector<pll> p, q;
	FOR(i,0,n/2) {
		ll x = a[i], y = a[n-1-i];
		if (x > y) swap(x,y);
		p.eb(x,y);
	}
	FOR(i,0,n/2) {
		ll x = b[i], y = b[n-1-i];
		if (x > y) swap(x,y);
		q.eb(x,y);
	}
	sort(all(p)), sort(all(q));

	return p == q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << (solve() ? "Yes" : "No") << endl;
}