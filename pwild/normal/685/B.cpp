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

vl d, s, c;
vl p[20];
vvl ch;

void dfs(ll i) {
	s[i] = 1;
	for (ll j: ch[i]) {
		d[j] = d[i]+1;
		dfs(j);
		s[i] += s[j];
	}

}

void dfs2(ll i) {
	ll smax = 0, jmax = -1;
	for (ll j: ch[i]) if (s[j] > smax) smax = s[j], jmax = j;
	
	for (ll j: ch[i]) dfs2(j);

	if (smax <= s[i]/2) {
		c[i] = i;
		return;
	}
	
	ll hi = jmax, lo = c[jmax];
	ll t = 0;
	while ((1 << t) < d[lo] - d[hi]) t++;
	
	if (s[i] - s[lo] <= s[i]/2) {
		c[i] = lo;
		return;
	}
	
	assert(s[i] - s[lo] > s[i]/2);
	assert(s[i] - s[hi] <= s[i]/2);
	while (hi != p[0][lo]) {
		while ((1 << t) >= d[lo] - d[hi]) t--;
		ll mid = p[t][lo];
		if (s[i] - s[mid] <= s[i]/2) hi = mid; else lo = mid;	
	}
	c[i] = hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q; cin >> n >> q;
	d.resize(n);
	s.resize(n);
	c.resize(n);
	FOR(k,0,20) p[k].resize(n,-1),
	ch.resize(n);
	p[0][0] = -1;
	d[0] = 0;
	FOR(i,1,n) {
		cin >> p[0][i], p[0][i]--;
		ch[p[0][i]].pb(i);
	}
	dfs(0);
	FOR(k,1,20) FOR(i,0,n) if (p[k-1][i] != -1) p[k][i] = p[k-1][p[k-1][i]];
	dfs2(0);
	
	while (q--) {
		ll i; cin >> i;
		cout << c[i-1]+1 << endl;
	}

}