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

const ll N = 100100;
ll a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	a[0] = 1;

	ll k = 0, res = 0;
	while (n--) {
		string com; cin >> com;
		if (com == "add") {
			res += a[k];
			if (res >= 1LL << 32) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
		} else if (com == "end") {
			k--;
		} else if (com == "for") {
			ll x; cin >> x;
			a[k+1] = min(ll(1e10),a[k]*x);
			k++;
		} else assert(0);
	}

	cout << res << endl;



}