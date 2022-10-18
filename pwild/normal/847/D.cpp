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

struct bit {
	ll n;
	vl a;

	bit(ll n): n(n), a(n+2) {}

	void add(ll i) {
		for (++i; i <= n+1; i += i & -i) a[i]++;
	}

	ll get(ll i) {
		ll res = 0;
		for (; i; i -= i & -i) res += a[i];
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, T; cin >> n >> T;

	vl t(n);
	FOR(i,0,n) cin >> t[i];
	FOR(i,0,n) t[i] = max(t[i],i+1);

	vl run(n);
	FOR(i,0,n) if (t[i] < T) run[i] = min(n,i+T-t[i]);
	
	vector<pll> ev(n);
	FOR(i,0,n) ev[i] = {t[i]-i,i};
	sort(all(ev));
	
	ll res = 0;
	bit b(n);
	for (const auto &p: ev) {
		ll i = p.yy;
		b.add(i);
		res = max(res,b.get(run[i]));
	}
	cout << res << endl;
}