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

vl a;
const ll K = 31;
ll invs[K][2];

void rec(vl p, ll k) {
	if (sz(p) == 0 || k < 0) return;
	
	vl q, r;
	for (ll i: p) {
		if (a[i] & (1 << k)) {
			invs[k][1] += sz(q);
			r.pb(i);
		} else {
			invs[k][0] += sz(r);
			q.pb(i);
		}
	}
	rec(q,k-1);
	rec(r,k-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	a.resize(n);
	FOR(i,0,n) cin >> a[i];
	
	vl v(n);
	iota(all(v),0);
	rec(v,K-1);
	
	ll res = 0, x = 0;
	FOR(k,0,K) {
		if (invs[k][0] > invs[k][1]) x += 1 << k;
		res += min(invs[k][0], invs[k][1]);
	}
	cout << res << " " << x << endl;
}