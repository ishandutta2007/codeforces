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

bool solve() {
	ll n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;
	
	auto check = [&](ll a, ll ab, ll ac) {
		ll x = a-ab-ac;
		return 0 <= x && x <= n-2;
	};

	FOR(ul,0,2) FOR(ur,0,2) FOR(dl,0,2) FOR(dr,0,2) {
		bool ok = check(u,ul,ur) && check(r,ur,dr) && check(d,dl,dr) && check(l,ul,dl);
		if (ok) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}
}