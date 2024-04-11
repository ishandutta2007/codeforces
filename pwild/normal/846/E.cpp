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

vl have, need;
vl p, k;
vvl ch;

void fail() {
	cout << "NO" << endl;
	exit(0);
}

ll dfs(ll i) {
	ll total = have[i]-need[i];

	for (ll j: ch[i]) {
		ll cur = dfs(j);
		if (cur < 0) {
			if (abs(cur * 1.0 * k[j]) > 2e17) fail();
			cur *= k[j];
		} 
		total += cur;
		if (abs(total) > 2e17) fail();
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	have.resize(n), need.resize(n);
	FOR(i,0,n) cin >> have[i];
	FOR(i,0,n) cin >> need[i];
	
	p.resize(n), k.resize(n);
	ch.resize(n);
	FOR(i,1,n) {
		cin >> p[i] >> k[i];
		p[i]--;
		ch[p[i]].pb(i);
	}
	
	cout << (dfs(0) >= 0 ? "YES" : "NO") << endl;
}