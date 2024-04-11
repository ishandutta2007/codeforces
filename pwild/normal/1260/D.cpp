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
	
	ll ns, len, nt, time;
	cin >> ns >> len >> nt >> time;

	vl a(ns);
	FOR(i,0,ns) cin >> a[i];
	sort(all(a),greater<ll>());
	
	vl l(nt), r(nt), d(nt);
	FOR(i,0,nt) cin >> l[i] >> r[i] >> d[i], l[i]--;
	
	ll kmin = 0, kmax = ns+1;
	while (kmax-kmin > 1) {
		ll k = (kmin+kmax)/2;
		
		vl v(len+1);
		FOR(i,0,nt) if (d[i] > a[k-1]) {
			v[l[i]]++;
			v[r[i]]--;
		}

		ll total = len+1, depth = 0;
		FOR(x,0,len+1) {
			depth += v[x];
			if (depth > 0) total += 2;
		}
		bool ok = total <= time;
		if (ok) kmin = k; else kmax = k;
	}
	cout << kmin << endl;
}