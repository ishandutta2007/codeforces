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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll go() {
	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;
	if (d <= k) return d*a;
	ll res = k*a;
	d -= k;
	// min(i*(t+k*a) + (d-i*k)*b) = d*b + min(i*(t+k*(a-b)))
	res += d*b;
	ll x = t + k*(a-b);
	if (x >= 0) return res;
	ll i = d/k;
	res += i*x;
	ll j = d%k;
	ll y = t+j*(a-b);
	if (y < 0) res += y;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << go() << endl;
}