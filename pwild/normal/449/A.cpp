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

ll f(ll m, ll n, ll k) {
	k += 2;
	if (k > n+m) return -1;

	ll res = 0;
	FOR(dir,0,2) {
		ll imin = max(1LL,k-n);
		FOR(i,imin,imin+10) {
			ll j = k-i;
			if (i >= 1 && i <= m && j >= 1 && j <= n)
				res = max(res,(m/i)*(n/j));
		}
		swap(m,n);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;
	cout << f(m,n,k) << endl;

}