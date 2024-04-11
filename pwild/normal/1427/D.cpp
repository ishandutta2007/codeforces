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
	FOR(i,0,n) cin >> a[i], a[i]--;

	vvl res;
	while (!is_sorted(all(a))) {
		vl b(n);
		FOR(i,0,n) b[a[i]] = i;

		FOR(i,0,n-1) if (b[i] > b[i+1]) {
			vl cuts = {0,b[i+1],b[i+1]+1,b[i]+1,n}, op;
			while (a[cuts[2]] == a[cuts[2]-1]+1) cuts[2]++;
			FOR(k,0,4) if (cuts[k+1] > cuts[k]) op.pb(cuts[k+1]-cuts[k]);
			res.pb(op);

			vl na;
			FORD(k,0,4) FOR(j,cuts[k],cuts[k+1]) na.pb(a[j]);
			a = na;

			break;
		}
	}

	cout << sz(res) << endl;
	for (vl op: res) {
		cout << sz(op);
		for (ll x: op) cout << " " << x;
		cout << endl;
	}
}