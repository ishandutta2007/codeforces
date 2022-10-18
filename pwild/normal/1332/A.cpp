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

bool check(ll a, ll b, ll x, ll xmin, ll xmax) {
	if (xmin == xmax) return a == 0 && b == 0;
	return x-a+b >= xmin && x-a+b <= xmax;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		ll x, y, xmin, ymin, xmax, ymax;
		cin >> x >> y >> xmin >> ymin >> xmax >> ymax;

		bool res = check(a,b,x,xmin,xmax) && check(c,d,y,ymin,ymax);
		cout << (res ? "Yes" : "No") << endl;
	}
}