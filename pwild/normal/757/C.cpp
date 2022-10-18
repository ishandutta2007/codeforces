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

const ll MOD[] = {123454411,123454349,123454339}, r[] = {752,2874,2348};
const ll M = 1e9 + 7;

struct num {
	ll a[3];
	num(ll x = 0) { FOR(i,0,3) a[i] = x; }
	void add(num n) { FOR(i,0,3) a[i] = (a[i] + n.a[i] + MOD[i]) % MOD[i]; }
	void shift() { FOR(i,0,3) a[i] = a[i] * r[i] % MOD[i]; }
	bool operator<(const num &n) const { return lexicographical_compare(a,a+3,n.a,n.a+3); }
	bool operator==(const num &n) const {
		FOR(i,0,3) if (a[i] != n.a[i]) return false;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	
	vector<num> rpow(n);
	rpow[0] = num(1);
	FOR(i,1,n) {
		rpow[i] = rpow[i-1];
		rpow[i].shift();
	}
	
	vector<num> gyms(m);
	FOR(i,0,n) {
		ll k; cin >> k;
		vl pokes(k);
		FOR(j,0,k) cin >> pokes[j];
		//sort(all(pokes));
		//pokes.erase(unique(all(pokes)),end(pokes));
		//k = sz(pokes);
		FOR(j,0,k) {
			ll t = pokes[j];
			gyms[t-1].add(rpow[i]);
		}
	}
	sort(all(gyms));
	
	ll res = 1, i = 0;
	while (i < m) {
		ll j = i+1;
		while (j < m && gyms[j] == gyms[i]) j++;

		ll k = j-i;
		while (k) res = res*k-- % M;
		i = j;
	}
	cout << res << endl;
}