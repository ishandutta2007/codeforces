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
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) {
		char c; cin >> c;
		a[i] = c == 'B';
	}
	
	FOR(k,0,2) {
		vl res, b = a;
		FOR(i,0,n-1) {
			if (b[i] != k) {
				b[i] = 1-b[i];
				b[i+1] = 1-b[i+1];
				res.pb(i+1);
			}
		}
		if (b[n-1] == k) {
			cout << sz(res) << endl;
			for (ll x: res) cout << x << " ";
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}