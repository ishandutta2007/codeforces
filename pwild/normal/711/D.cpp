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

vl a;
vl mark;
vl d;
vl lens;

void dfs(ll i) {
	mark[i] = 1;
	if (mark[a[i]] == 1) lens.pb(d[i]+1 - d[a[i]]);
	if (mark[a[i]] == 0) d[a[i]] = d[i] + 1, dfs(a[i]);
	mark[i] = 2;
}

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	a.resize(n);
	FOR(i,0,n) cin >> a[i], a[i]--;
	
	mark.resize(n);
	d.resize(n);
	FOR(i,0,n) if (!mark[i]) dfs(i);
	

	ll res = 1;
	for (ll l: lens) {
		n -= l;
		ll cur = 1;
		FOR(i,0,l) cur = 2*cur % MOD;
		cur = (cur + MOD-2) % MOD;
		res = res*cur % MOD;
	}
	FOR(i,0,n) res = 2*res % MOD;
	cout << res << endl;

}