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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	const ll N = 3e6;
	vl pf(N), pr = {0};
	iota(all(pf),0);
	FOR(i,2,N) if (pf[i] == i) {
		pr.pb(i);
		for (ll j = i*i; j < N; j += i) pf[j] = min(pf[j],i);
	}
	
	ll n; cin >> n;
	multiset<ll> b;
	FOR(i,0,2*n) {
		ll x; cin >> x;
		b.insert(x);
	}
	
	FOR(i,0,n) {
		ll x = *b.rbegin();
		b.erase(b.find(x));
		if (pf[x] == x) {
			ll y = lower_bound(all(pr),x)-begin(pr);
			assert(pr[y] == x);
			b.erase(b.find(y));
			cout << y << " ";
		} else {
			ll y = x/pf[x];
			b.erase(b.find(y));
			cout << x << " ";
		}
	}
	cout << endl;
}