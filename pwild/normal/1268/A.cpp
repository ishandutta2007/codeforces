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
	
	ll n, k;
	cin >> n >> k;
	
	vector<string> a;
	FOR(i,0,n) {
		char c; cin >> c;
		if (i%k == 0) a.pb("");
		a.back().pb(c);
	}
	
	FOR(j,1,sz(a)) {
		if (a[j] < a[0]) {
			break;
		}
		if (a[j] > a[0]) {
			for (ll t = k-1; t >= 0; t--) {
				if (a[0][t] == '9') {
					a[0][t] = '0';
				} else {
					a[0][t]++;
					break;
				}
			}
			break;
		}
	}

	FOR(j,1,sz(a)) {
		a[j] = a[0].substr(0,sz(a[j]));
	}
	
	cout << n << endl;
	for (string b: a) cout << b;
	cout << endl;
}