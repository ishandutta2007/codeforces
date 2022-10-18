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

void solve(ll n) {
	ll k = 0;
	while ((1LL << k) - 1 < n) k++;
	
	vl a(k);
	FOR(i,0,k) {
		a[i] = min(1LL << i, n);
		n -= a[i];
	}

	FORD(i,0,k-1) {
		if (a[i] <= a[i+1]) break;
		ll b = (a[i]-a[i+1]+1)/2;
		a[i] -= b, a[i+1] += b;
	}

	cout << k-1 << endl;
	FOR(i,0,k-1) cout << a[i+1]-a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		solve(n);
	}
}