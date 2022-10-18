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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k, x; cin >> n >> k >> x;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll sgn = 1, zeroes = 0;
	FOR(i,0,n) {
		if (a[i] < 0) sgn = -sgn;
		if (a[i] == 0) zeroes++;
	}
	
	if (zeroes) {
		FOR(i,0,n) if (a[i] == 0 && k) {
			if (sgn == 1) a[i] -= x, sgn = -1;
			else a[i] += x;
			k--, zeroes--;
		}
	}
	if (sgn == 1) {
		ll j = 0;
		FOR(i,1,n) if (abs(a[i]) < abs(a[j])) j = i;
		if (a[j] < 0) {
			while (a[j] <= 0 && k) {
				a[j] += x;
				k--;
			}
		} else {
			while (a[j] >= 0 && k) {
				a[j] -= x;
				k--;
			}
		}
	}
	
	set<pll> q;
	FOR(i,0,n) q.emplace(abs(a[i]),i);
	while (k--) {
		ll i = begin(q)->yy;
		q.erase(begin(q));
		if (a[i] < 0) a[i] -= x;
		else a[i] += x;
		q.emplace(abs(a[i]),i);
	}

	FOR(i,0,n) cout << a[i] << " \n"[i+1 == n];
}