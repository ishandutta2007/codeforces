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

ll solve_naive(vl a, vl b) {
	if (sz(b) == 0) return 1;
	ll i = find(all(a),b[0]) - begin(a);
	if (i == sz(a)) return 0;

	ll res = 0;
	for (ll j: {i-1,i+1}) {
		if (j < 0 || j >= sz(a)) continue;
		vl na = a, nb = b;
		na.erase(begin(na)+j);
		nb.erase(begin(nb));
		res += solve_naive(na,nb);
	}
	return res;
}

const ll MOD = 998244353;

ll solve(vl a, vl b) {
	ll n = sz(a);
	for (ll &x: a) x--;
	for (ll &x: b) x--;

	vl p(n);
	FOR(i,0,n) p[a[i]] = i;
	for (ll &x: b) x = p[x];
	
	set<ll> todo(all(b));
	todo.insert(-1);
	todo.insert(n);

	ll res = 1;
	for (ll x: b) {
		todo.erase(x);
		res *= 2 - todo.count(x-1) - todo.count(x+1);
		res %= MOD;
	}
	return res;
}

void test() {
	FOR(iter,0,10000) {
		ll n = 2 + rand() % 10;
		ll k = 1 + rand() % (n-1);
		vl a(n), b(n);
		iota(all(a),1);
		iota(all(b),1);
		random_shuffle(all(a));
		random_shuffle(all(b));
		b.resize(k);
		assert(solve(a,b) == solve_naive(a,b));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	test();

	ll tc; cin >> tc;
	while (tc--) {
		ll n, k;
		cin >> n >> k;
		vl a(n), b(k);
		FOR(i,0,n) cin >> a[i];
		FOR(i,0,k) cin >> b[i];
		cout << solve(a,b) << endl;
	}

}