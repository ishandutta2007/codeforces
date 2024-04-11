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

struct num {
	ll a[3];
	num(ll x = 0) { FOR(i,0,3) a[i] = x; }
	void add(num n) { FOR(i,0,3) a[i] = (a[i] + n.a[i] + MOD[i]) % MOD[i]; }
	void shift() { FOR(i,0,3) a[i] = a[i] * r[i] % MOD[i]; }
	bool operator<(const num &n) const { return lexicographical_compare(a,a+3,n.a,n.a+3); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	string disc; cin >> disc;
	disc = disc + disc;
	ll m; cin >> m;
	vector<string> games(m);
	FOR(i,0,m) cin >> games[i];
	
	num rk(-1);
	FOR(i,1,k) rk.shift();

	vector<num> ghash(m);
	map<num,ll> id;
	FOR(i,0,m) {
		FOR(j,0,k) ghash[i].shift(), ghash[i].add(num(games[i][j]-'a'));
		id[ghash[i]] = i;
	}


	vector<num> dhash(n*k);
	FOR(j,0,k) dhash[0].shift(), dhash[0].add(num(disc[j]-'a'));
	FOR(i,0,n*k-1) {
		dhash[i+1] = dhash[i];
		num t = rk;
		FOR(k,0,3) t.a[k] = t.a[k] * (disc[i]-'a') % MOD[k];
		dhash[i+1].add(t), dhash[i+1].shift(), dhash[i+1].add(num(disc[i+k]-'a'));
	}
	FOR(offs,0,k) {
		set<ll> taken;
		vl res;
		bool ok = true;
		for (ll i = offs; i < n*k; i += k) {
			if (has(id,dhash[i]) && !has(taken,id[dhash[i]])) {
				taken.insert(id[dhash[i]]);
				res.pb(id[dhash[i]]);
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl;
			for (ll x: res) cout << x+1 << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}