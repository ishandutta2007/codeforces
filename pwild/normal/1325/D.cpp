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

vl solve(ll a, ll b) {
	if (a%2 != b%2) return {-1};
	if (a > b) return {-1};
	if (a == 0 && b == 0) return {};
	if (a == b) return {a};
	
	ll r = (b-a)/2;
	if ((a&r) == 0) return {a^r, r};

	return {a,r,r};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll a, b;
	cin >> a >> b;

	vl res = solve(a,b);
	if (res == vl{-1}) {
		cout << -1 << endl;
	} else {
		cout << sz(res) << endl;
		for (ll x: res) cout << x << " ";
		cout << endl;
	}
}