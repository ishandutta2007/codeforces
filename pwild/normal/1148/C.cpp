#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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
	vl p(n+1);
	FOR(i,1,n+1) cin >> p[i];
	
	vector<pll> res;
	res.reserve(5*n);
	
	map<ll,ll> q;
	FOR(i,1,n+1) q[p[i]] = i;

	auto do_swap = [&](ll i, ll j) {
		swap(p[i],p[j]);
		q[p[i]] = i;
		q[p[j]] = j;
		
		if (abs(i-j) >= n/2) {
			res.eb(i,j);
			return;
		}

		if (i <= n/2 && j <= n/2) {
			res.eb(i,n);
			res.eb(j,n);
			res.eb(i,n);
		} else if (i <= n/2) {
			res.eb(i,n);
			res.eb(1,j);
			res.eb(1,n);
			res.eb(1,j);
			res.eb(i,n);
		} else if (j <= n/2) {
			res.eb(j,n);
			res.eb(1,i);
			res.eb(1,n);
			res.eb(1,i);
			res.eb(j,n);
		} else {
			res.eb(i,1);
			res.eb(j,1);
			res.eb(i,1);
		}
	};

	FOR(i,1,n+1) if (p[i] != i) {
		ll j = q[i];
		do_swap(i,j);
	}
	
	cout << sz(res) << '\n';
	for (pll pr: res) cout << pr.xx << " " << pr.yy << '\n';

}