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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll h, n;
		cin >> h >> n;
		vl a(n+1);
		FOR(i,0,n) cin >> a[i];

		ll res = 0, i = 0;
		while (i+1 < n) {
			if (a[i+1] == a[i]-1) {
				if (a[i+2] == a[i]-2) {
					i += 2;
				} else {
					a[i+1] = a[i]-2;
					i++, res++;
				}
			} else {
				a[i] = a[i+1]+1;
			}
		}
		cout << res << endl;
	}
}