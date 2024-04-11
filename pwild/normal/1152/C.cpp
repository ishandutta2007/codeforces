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

ll lcm(ll a, ll b) { return a/__gcd(a,b) * b; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a,b);

	if (a == b) {
		cout << 0 << endl;
		return 0;
	}

	ll k = b-a;
	vl divs;
	for (ll d = 1; d*d <= k; d++) if (k%d == 0) divs.pb(d), divs.pb(k/d);
	
	auto val = [&](ll cur) { return lcm(a+cur,b+cur); };

	ll res = 0, vres = val(res);
	for (ll d: divs) {
		ll cur = (d-b%d)%d;
		ll vcur = val(cur);
		if (mp(vcur,cur) < mp(vres,res)) res = cur, vres = vcur;
	}
	cout << res << endl;
}