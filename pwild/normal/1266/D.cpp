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
	
	ll n, m;
	cin >> n >> m;

	vl a(n);
	while (m--) {
		ll i, j, c;
		cin >> i >> j >> c;
		i--, j--;
		a[i] -= c, a[j] += c;
	}
	
	vl pos, neg;
	FOR(i,0,n) {
		if (a[i] > 0) pos.pb(i);
		if (a[i] < 0) neg.pb(i);
	}
	
	ll i = 0, j = 0;
	vector<tuple<ll,ll,ll>> res;
	while (i < sz(pos) && j < sz(neg)) {
		ll u = pos[i], v = neg[j];
		ll take = min(a[u], -a[v]);
		res.pb({v,u,take});
		a[u] -= take, a[v] += take;
		if (a[u] == 0) i++;
		if (a[v] == 0) j++;
	}

	cout << sz(res) << endl;
	for (auto [u,v,c]: res) cout << u+1 << " " << v+1 << " " << c << endl;
}