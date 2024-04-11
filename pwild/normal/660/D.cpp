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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	vl x(n), y(n);
	FOR(i,0,n) cin >> x[i] >> y[i];

	vector<pll> a;
	FOR(i,0,n) FOR(j,i+1,n) {
		ll dx = x[i]-x[j], dy = y[i]-y[j];
		if (dx < 0) dx = -dx, dy = -dy;
		if (dx == 0 && dy < 0) dy = -dy;
		a.eb(dx,dy);
	}
	sort(all(a));
	ll res = 0;
	for (ll i = 0; i < sz(a); ) {
		ll j = i+1;
		while (j < sz(a) && a[j] == a[i]) j++;
		res += (j-i)*(j-i-1)/2;
		i = j;
	}
	assert (res % 2 == 0);
	cout << res/2 << endl;



}