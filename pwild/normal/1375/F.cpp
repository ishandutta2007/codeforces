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
	vl a(3);
	FOR(i,0,3) cin >> a[i];

	cout << "First" << endl;

	ll k;
	auto turn = [&](ll x) {
		cout << x << endl;
		cin >> k, k--;
		if (k < 0) exit(0);
		a[k] += x;
//		FOR(i,0,3) cerr << a[i] << " ";
//		cerr << endl;
	};

	turn(1e10);
	
	ll x = 3*a[k] - accumulate(all(a),0LL);
	turn(x);
	
	ll i = min_element(all(a)) - begin(a);
	ll j = 3 ^ i ^ k;

	assert(a[j]-a[i] == a[k]-a[j]);
	turn(a[j]-a[i]);

}