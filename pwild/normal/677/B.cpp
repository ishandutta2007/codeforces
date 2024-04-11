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

	ll n, k, h; cin >> n >> h >> k;
	
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll curh = 0, i = 0, t = 0;
	while (true) {
		while (i < n && curh + a[i] <= h) curh += a[i++];
		
		ll dt;
		if (i < n) {
			ll dx = a[i] - (h-curh);
			assert (dx > 0);
			dt = (dx+k-1)/k;
		} else {
			dt = (curh+k-1)/k;
		}
		curh -= dt*k, t += dt;
		if (curh < 0) curh = 0;
		if (curh == 0 && i == n) break;
	}
	cout << t << endl;
}