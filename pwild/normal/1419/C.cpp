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

ll solve(ll x, vl a) {
	ll n = sz(a);
	if (a == vl(n,x)) return 0;

	ll sum = accumulate(all(a),0LL);
	if (sum == n*x) return 1;

	ll cnt = 0;
	for (ll y: a) cnt += y == x;
	if (cnt > 0) return 1;

	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, x;
		cin >> n >> x;

		vl a(n);
		FOR(i,0,n) cin >> a[i];
		
		cout << solve(x,a) << endl;
	}
}