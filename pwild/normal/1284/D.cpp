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

	vl a(n), b(n), c(n), d(n);
	FOR(i,0,n) cin >> a[i] >> b[i] >> c[i] >> d[i];

	FOR(dir,0,2) {
		vector<pll> events;
		FOR(i,0,n) events.eb(a[i],~i), events.eb(b[i],i);
		sort(all(events));
		
		set<pll> cs, ds;
		for (auto [t,i]: events) {
			if (i >= 0) {
				pll cur(c[i],d[i]);
				cs.erase({c[i],i});
				ds.erase({d[i],i});
			} else {
				i = ~i;
				cs.emplace(c[i],i);
				ds.emplace(d[i],i);
				if (ds.begin()->xx < cs.rbegin()->xx) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		
		swap(a,c), swap(b,d);
	}
	cout << "YES" << endl;
}