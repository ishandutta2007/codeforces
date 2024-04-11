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
	
	ll n, amax, bmax;
	cin >> n >> bmax >> amax;

	ll a = amax, b = bmax;

	FOR(i,0,n) {
		if (a == 0 && b == 0) {
			cout << i << endl;
			return 0;
		}
		ll s; cin >> s;
		if (s) {
			if (a < amax && b > 0) {
				a++, b--;
			} else if (a > 0) {
				a--;
			} else {
				b--;
			}
		} else {
			if (a > 0) {
				a--;
			} else {
				b--;
			}
		}
	}
	cout << n << endl;	
}