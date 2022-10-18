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

struct comp_sz {
	bool operator()(const vl &a, const vl &b) {
		if (sz(a) != sz(b)) return sz(a) < sz(b);
		return a < b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;

	vector<pll> res;
	
	set<vl,comp_sz> S;
	vvl T;
	
	FOR(i,1,n+1) S.insert({i});
	while (sz(S) > 1) {
		auto a = *begin(S);
		auto b = *next(begin(S));

		if (sz(a) == sz(b)) {
			S.erase(begin(S));
			S.erase(begin(S));
			FOR(i,0,sz(a)) res.eb(a[i],b[i]);
			for (ll x: b) a.pb(x);
			S.insert(a);
		} else {
			S.erase(begin(S));
			T.pb(a);
		}
	}

	while (sz(S)) {
		T.pb(*begin(S));
		S.erase(begin(S));
	}
	
	sort(all(T),comp_sz());
	
	vl a = T.back();
	T.pop_back();
	reverse(all(T));
	
	while (sz(T) > 1) {
		vl &b = T[sz(T)-1];
		vl &c = T[sz(T)-2];

		if (sz(b) == sz(c)) {
			FOR(i,0,sz(b)) res.eb(b[i],c[i]);
			for (ll x: b) c.pb(x);
			T.pop_back();
		} else {
			vl d;
			FOR(i,0,sz(b)) {
				d.pb(a.back());
				a.pop_back();
			}
			T.pb(d);
		}
	}
	
	cout << sz(res) << '\n';
	for (auto [x,y]: res) cout << x << " " << y << '\n';
}