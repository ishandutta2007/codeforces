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

ll rev(ll a) {
	ll b = 0;
	FOR(i,0,6) b = 2*b + a%2, a /= 2;
	return b;
}

ll solve(ll a) {
	a = rev(a);
	vl p = {0,5,3,2,4,1};
	
	ll b = 0, c = 0;
	FOR(i,0,6) if (a & (1 << p[i])) b += 1 << i;
	FOR(i,0,6) if (a & (1 << i)) c += 1 << p[i];
	b = rev(b), c = rev(c);
	assert(b == c);
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll a; cin >> a;
	cout << solve(a) << endl;

}