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

vl p;
ll Find(ll x) {
	if (x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(ll x, ll y) {
	x = Find(x), y = Find(y);
	if (rand() & 1) swap(x,y);
	p[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k; cin >> n >> m >> k;
	vl col(n);
	FOR(i,0,n) cin >> col[i];
	p.resize(n);
	FOR(i,0,n) p[i] = i;
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		Union(a-1,b-1);
	}
	ll res = n;
	vvl comp(n);
	FOR(i,0,n) comp[Find(i)].pb(i);
	FOR(i,0,n) if (sz(comp[i])) {
		map<ll,ll> cnt;
		for (ll j: comp[i]) cnt[col[j]]++;
		ll maxcnt = 0;
		for (auto p: cnt) maxcnt = max(maxcnt,p.yy);
		res -= maxcnt;
	}
	cout << res << endl;
}