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

const ll N = 1010;
ll col[N];
vvl v[N];

void parse(ll i, string s) {
	stringstream ss(s);
	char foo;
	while (true) {
		ll len; ss >> len;
		vl cur(len);
		FOR(i,0,len) ss >> foo >> cur[i];
		sort(all(cur));
		v[i].pb(cur);
		if (!(ss >> foo)) break;
	}
}

bool ok = true;
vector<pll> res;

void fail() {
	cout << -1 << endl;
	exit(0);
}

void rec(ll i) {
	vl comp = {i};
	for (vl &w: v[i]) for (ll j: w) comp.pb(j);
	
	ll centroid = i, centroidmaxsize = oo;
	for (ll j: comp) {
		ll maxsize = 0;
		for (vl &w: v[j]) maxsize = max(maxsize,sz(w));
		if (maxsize < centroidmaxsize) centroid = j, centroidmaxsize = maxsize;
	}
	
	if (2*centroidmaxsize > sz(comp)) fail();
	
	i = centroid;

	ll C = sz(v[i]);
	
	col[i] = -1;
	FOR(c,0,C) for (ll j: v[i][c]) col[j] = c;;
	
	vl bestj(C,-1);
	vl bestisize(C,oo);

	for (ll j: comp) if (j != i) {
		ll cnt = 0, isize;
		vvl vj;
		for (vl &w: v[j]) {
			vl nw;
			bool cur = false, hasi = false;
			for (ll k: w) {
				if (col[j] == col[k]) nw.pb(k);
				else cur = true;
				if (k == i) hasi = true;
			}
			if (sz(nw)) vj.pb(nw);
			if (hasi) isize = sz(w);
			cnt += cur;
		}
		if (cnt != 1) fail();
		if (isize < bestisize[col[j]]) bestj[col[j]] = j, bestisize[col[j]] = isize;
		v[j] = vj;
	}
	
	for (ll j: bestj) res.eb(i,j), rec(j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	
	FOR(i,1,n+1) {
		string s; cin >> s;
		parse(i,s);
	}
	
	rec(1);
	cout << n-1 << endl;
	for (pll p: res) cout << p.xx << " " << p.yy << endl;
}