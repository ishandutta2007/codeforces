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

void solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	map<ll,vl> occ;
	FOR(i,0,n) occ[a[i]].pb(i);
	
	set<ll> gr;
	FOR(i,0,n) gr.insert(i);
	
	for (auto [x,v]: occ) {
		for (ll i: v) gr.erase(i);
		if (sz(v) < 3) continue;

		if (gr.empty()) {
			cout << "YES" << endl;
			ll i = v[1];
			cout << i << " 1 " << n-i-1 << endl;
			return;
		} else {
			ll i = *begin(gr), j = *rbegin(gr);
			ll cnt = 0;
			for (ll k: v) if (i < k && k < j) cnt++;
			
			if (cnt + sz(gr) != j-i+1) continue;

			if (cnt == 0 && i > 0 && a[i-1] == x && i-1 != v[0]) i--, cnt++;
			if (cnt == 0 && j+1 < n && a[j+1] == x && j+1 != v.back()) j++, cnt++;
			if (cnt > 0 && v[0] < i && j < v.back()) {
				cout << "YES" << endl;
				cout << i << " " << j-i+1 << " " << n-j-1 << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}