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

string s;
ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	n = sz(s);
	ll lc = 0, rc = 0;
	FOR(i,0,n) if (s[i] == 'L') lc++; else rc++;
	
	ll cnt = -1;
	vl go(n,-1);
	set<ll> ls, rs;
	vl beginl, beginr;
	FOR(i,0,n) {
		if (s[i] == 'L') {
			if (sz(rs)) {
				go[*begin(rs)] = i;
				rs.erase(begin(rs));
			} else {
				beginl.pb(i);
				cnt++;
			}
			ls.insert(i);
		} else {
			if (sz(ls)) {
				go[*begin(ls)] = i;
				ls.erase(begin(ls));
			} else {
				beginr.pb(i);
				cnt++;
			}
			rs.insert(i);
		}
	}

	vvl llv, lr, rl, rr;

	for (ll x: beginl) {
		ll cur = x;
		vl v;
		while (true) {
			v.pb(cur+1);
			if (go[cur] == -1) break;
			cur = go[cur];
		}
		if (s[cur] == 'L') llv.pb(v); else lr.pb(v);
	}
	for (ll x: beginr) {
		ll cur = x;
		vl v;
		while (true) {
			v.pb(cur+1);
			if (go[cur] == -1) break;
			cur = go[cur];
		}
		if (s[cur] == 'L') rl.pb(v); else rr.pb(v);
	}
	
	vl res;

	swap(llv,lr);
	swap(rl,rr);

	assert(abs(sz(lr)-sz(rl)) <= 1);

	

	if (sz(lr) > sz(rl)) {
		for (const vl &v: llv) for (ll x: v) res.pb(x);
		FOR(i,0,sz(rl)) {
			for (ll x: lr[i]) res.pb(x);
			for (ll x: rl[i]) res.pb(x);
		}
		for (ll x: lr[sz(rl)]) res.pb(x);
		for (const vl &v: rr) for (ll x: v) res.pb(x);
	} else {
		for (const vl &v: rr) for (ll x: v) res.pb(x);
		FOR(i,0,sz(rl)-1) {
			for (ll x: rl[i]) res.pb(x);
			for (ll x: lr[i]) res.pb(x);
		}
		if (sz(rl)) for (ll x: rl[sz(rl)-1]) res.pb(x);
		for (const vl &v: llv) for (ll x: v) res.pb(x);
		if (sz(rl) && sz(lr) == sz(rl)) for (ll x: lr[sz(rl)-1]) res.pb(x);
	}
	
	cout << cnt << endl;
	FOR(i,0,n-1) cout << res[i] << " ";
	cout << res[n-1] << endl;




/*
	pair<ll,vl> sl, sr;
	sl = sr = {oo,{}};
	if (lc >= rc) sl = f();
	FOR(i,0,n) if (s[i] == 'L') s[i] = 'R'; else s[i] = 'L';
	if (lc <= rc) sr = f();
	
	auto res = min(sl,sr);

	cout << res.xx << endl;
	FOR(i,0,n-1) cout << res.yy[i] << " ";
	cout << res.yy[n-1] << endl;
*/
}