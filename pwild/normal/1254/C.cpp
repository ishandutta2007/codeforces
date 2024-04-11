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

ll area(ll i, ll j, ll k) {
	if (i == j || i == k || j == k) return 0;
	cout << "1 " << i+1 << " " << j+1 << " " << k+1 << endl;
	ll res; cin >> res;
	return res;
}

ll sign(ll i, ll j, ll k) {
	if (i == j || i == k || j == k) return 0;
	cout << "2 " << i+1 << " " << j+1 << " " << k+1 << endl;
	ll res; cin >> res;
	return res;
}

const ll q[3][3] = {{7,6,5},{0,-1,4},{1,2,3}};

int main() {
	ll n; cin >> n;

	vl top(n);
	FOR(i,0,n) top[i] = sign(0,1,i);
	
	vl a(n);
	FOR(i,0,n) a[i] = area(0,1,i);
	
	ll lo = 0, hi = 0;
	FOR(i,0,n) if (top[i] > 0 && a[i] > a[hi]) hi = i;
	FOR(i,0,n) if (top[i] < 0 && a[i] > a[lo]) lo = i;
	
	vl left(n);
	left[0] = 1, left[1] = -1;
	FOR(i,0,n) if (top[i] > 0) left[i] = sign(0,hi,i);
	FOR(i,0,n) if (top[i] < 0) left[i] = -sign(0,lo,i);
	
	vl res(n);
	iota(all(res),0);

	auto id = [&](ll i) {
		ll quad = q[1-top[i]][1-left[i]];
		ll sa = quad%4 == 3 ? -a[i] : a[i];
		return mp(quad, sa);
	};

	sort(all(res),[&](ll i, ll j) { return id(i) < id(j); });

	FOR(i,0,n) {
		auto [q,sa] = id(i);
//		cerr << i << " " << top[i] << " " << left[i] << " " << a[i] << " " << q << " " << sa << endl;
	}
	
	cout << 0;
	for (ll x: res) cout << " " << x+1;
	cout << endl;
}