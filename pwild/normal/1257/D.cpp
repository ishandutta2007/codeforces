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

ll solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vl best(n+1);
	ll m; cin >> m;
	while (m--) {
		ll pow, end;
		cin >> pow >> end;
		best[end] = max(best[end],pow);
	}
	FORD(i,0,n) best[i] = max(best[i],best[i+1]);
	
	ll i = 0, res = 0;
	while (i < n) {
		ll take = 0, strongest = 0;
		while (i+take < n && best[take+1] >= max(strongest, a[i+take])) {
			strongest = max(strongest, a[i+take]), take++;
		}
		if (take == 0) return -1;
		i += take, res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}