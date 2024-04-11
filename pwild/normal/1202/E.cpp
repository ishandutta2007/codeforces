#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct suffix_array {
	ll n;
	vvl p; // p[k][i] = rank of prefix i when sorting by first 2^k characters
	vl idx; // idx[j] = starting index of prefix of rank j
	
	suffix_array(vl s): n(sz(s)), p(1,s) { // O(n*log^2 n)
		for (ll k = 1, step = 1; step/2 < n; k++, step *= 2) {
			vector<pair<pll,ll>> v(n);
			FOR(i,0,n) v[i] = {{p[k-1][i], i+step < n ? p[k-1][i+step] : -oo}, i};
			sort(all(v));
			
			vl q(n);
			FOR(j,1,n) q[ v[j].yy ] = v[j].xx == v[j-1].xx ? q[ v[j-1].yy ] : j;
			p.pb(q);
		}
		idx.resize(n);
		FOR(i,0,n) idx[ p[sz(p)-1][i] ] = i;
	}

	ll lcp(ll x, ll y) { // longest common prefix of suffixes starting at x and y
		if (x == y) return sz(idx)-x;
		ll res = 0;
		FORD(k,0,sz(p)) {
			if (max(x,y) >= n) break;
			if (p[k][x] == p[k][y]) x += 1 << k, y += 1 << k, res += 1 << k;
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string t; cin >> t;
	ll n; cin >> n;
	vector<string> s(n);
	FOR(i,0,n) cin >> s[i];
	
	vvl res(2,vl(sz(t)));
	FOR(dir,0,2) {
		vl seq, start(n);
		for (char c: t) seq.pb(c);
		seq.pb(1);
		FOR(i,0,n) {
			start[i] = sz(seq);
			for (char c: s[i]) seq.pb(c);
			seq.pb(-i);
		}

		suffix_array S(seq);
		vector<pll> ev;
		FOR(i,0,n) {
			ll x = start[i];
			ll len = sz(s[i]);

			ll jmin = S.p.back()[x];
			ev.eb(jmin,1);
			ll jmax = sz(seq);
			
			while (jmax-jmin > 1) {
				ll j = (jmin+jmax)/2;
				ll y = S.idx[j];
				if (S.lcp(x,y) < len) jmax = j; else jmin = j;
			}
			ev.eb(jmax,-1);
		}

		sort(all(ev));
		ll j = 0, cnt = 0;
		
		FOR(i,0,sz(seq)) {
			while (j < sz(ev) && ev[j].xx == i) {
				cnt += ev[j++].yy;
			}
			if (S.idx[i] < sz(t)) res[dir][S.idx[i]] = cnt;
		}

		reverse(all(t));
		FOR(i,0,n) reverse(all(s[i]));
	}
	
	reverse(all(res[1]));
	FOR(dir,0,2) FOR(i,0,sz(t)) {
//		cout << res[dir][i] << " \n"[i+1==sz(t)];
	}
	
	long long ans = 0;
	FOR(i,1,sz(t)) ans += res[0][i] * 1LL * res[1][i-1];
	cout << ans << endl;

}