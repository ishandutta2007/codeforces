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
	
	vector<string> t12;
	FOR(h,1,13) FOR(m,0,60) {
		string s(5,':');
		s[0] = '0' + h/10, s[1] = '0' + h%10;
		s[3] = '0' + m/10, s[4] = '0' + m%10;
		t12.pb(s);
	}

	vector<string> t24;
	FOR(h,0,24) FOR(m,0,60) {
		string s(5,':');
		s[0] = '0' + h/10, s[1] = '0' + h%10;
		s[3] = '0' + m/10, s[4] = '0' + m%10;
		t24.pb(s);
	}
	
	ll x; cin >> x;
	string s; cin >> s;
	if (x == 12) {
		ll best = oo;
		string res;
		for (string t: t12) {
			ll cur = 0;
			FOR(i,0,5) if (s[i] != t[i]) cur++;
			if (cur < best) best = cur, res = t;
		}
		cout << res << endl;
	} else {
		ll best = oo;
		string res;
		for (string t: t24) {
			ll cur = 0;
			FOR(i,0,5) if (s[i] != t[i]) cur++;
			if (cur < best) best = cur, res = t;
		}
		cout << res << endl;
	}

}