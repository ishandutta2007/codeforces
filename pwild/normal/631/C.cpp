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
	
	ll n, m; cin >> n >> m;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vector<pll> v(m);
	FOR(i,0,m) cin >> v[i].xx >> v[i].yy;
	
	vb mark(m,true);
	ll maxy = -1;
	FORD(i,0,m) {
		if (v[i].yy <= maxy) mark[i] = false;
		else maxy = v[i].yy;
	}
	
	vector<pll> v2;
	FOR(i,0,m) if (mark[i]) v2.pb(v[i]);
	v2.pb({0,0});
	m = sz(v2) - 1;

	multiset<ll> s;
	FOR(i,0,maxy) s.insert(a[i]);
	FOR(i,0,m) {
		FORD(j,v2[i+1].yy,v2[i].yy) {
			if (v2[i].xx == 1) {
				a[j] = *s.rbegin();
				auto it = s.find(a[j]);
				s.erase(it);
			} else {
				a[j] = *s.begin();
				s.erase(s.begin());
			}
		}

	}

	FOR(i,0,n) cout << a[i] << " \n"[i+1==n];



}