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

const vl primes = {2,3,5,7,11,13,17,19,23,29};

void solve(ll n) {
	ll M = 2*n*n;
	vl smooth = {1};
	FOR(i,0,sz(primes)) {
		ll p = primes[i];
		vl nsmooth;
		for (ll x: smooth) {
			for (ll y = x; y <= M; y *= p) nsmooth.pb(y);
		}
		smooth = nsmooth;
		sort(all(smooth),greater<ll>());
		
		if (sz(smooth) < n) continue;

		vl v(begin(smooth),begin(smooth)+n);
		vl cnt(i+1);
		FOR(j,0,i+1) for (ll x: v) if (x%primes[j] == 0) cnt[j]++;

		if (*min_element(all(cnt)) < (n+1)/2) continue;

		for (ll x: v) cout << x << " ";
		cout << endl;
		return;
	}
	assert(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	solve(n);


}