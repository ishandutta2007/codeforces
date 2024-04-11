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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl x(n), y(n);
	FOR(i,0,n) cin >> x[i] >> y[i];

	ll res = (n*(n-1)*(n-2))/6;
	FOR(i,0,n) {
		vector<pll> ang(i);
		FOR(j,0,i) {
			ang[j] = {x[j]-x[i],y[j]-y[i]};
			if (ang[j] < pll(0,0)) ang[j].xx = -ang[j].xx, ang[j].yy = -ang[j].yy;
			ll g = gcd(abs(ang[j].xx), abs(ang[j].yy));
			ang[j].xx /= g, ang[j].yy /= g;
		}
		sort(all(ang));
		ll j = 0;
		while (j < i) {
			auto a = ang[j];
			ll k = j;
			while (ang[j] == a) j++;
			k = j-k;
			res -= (k*(k-1))/2;
		}
	}
	cout << res << endl;

}