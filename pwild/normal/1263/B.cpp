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
		ll n; cin >> n;
		vector<string> a(n);
		FOR(i,0,n) cin >> a[i];
		ll res = 0;
		FOR(i,0,n) {
			bool ok = true;
			FOR(j,0,i) if (a[j] == a[i]) ok = false;
			if (ok) continue;
			set<char> avail;
			FOR(x,0,10) avail.insert('0' + x);
			FOR(j,0,n) avail.erase(a[j][0]);
			a[i][0] = *begin(avail);
			res++;
		}
		cout << res << endl;
		FOR(i,0,n) cout << a[i] << endl;
	}
}