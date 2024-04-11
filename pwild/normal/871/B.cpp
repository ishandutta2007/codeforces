#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) {
		cout << "? " << i << " 0" << endl;
		cin >> a[i];
	}
	FOR(i,0,n) {
		cout << "? 0 " << i << endl;
		cin >> b[i];
	}
	
	auto c = [&](ll i, ll j) { return a[i]^b[j]^a[0]; };

	ll res = 0;
	vl ansp, ansq;
	FOR(k,0,n) {
		vl p(n), q(n);
		FOR(i,0,n) q[i] = c(k,i);
		FOR(i,0,n) p[i] = q[0] ^ c(i,0);
		
		bool ok = true;
		FOR(i,0,n) if (p[i] >= n) ok = false;
		FOR(i,0,n) if (q[i] >= n) ok = false;
		if (!ok) continue;
		FOR(i,0,n) if (p[q[i]] != i) ok = false;
		FOR(i,0,n) if (q[p[i]] != i) ok = false;
		
		if (ok) {
			if (res == 0) ansp = p, ansq = q;
			res++;
		}
	}
	cout << "!" << endl;
	cout << res << endl;
	FOR(i,0,n) cout << ansp[i] << " ";
	cout << endl;
}