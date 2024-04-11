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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	vector<pair<char,ll>> a;
	FOR(i,0,sz(s)) if (i == 0 || s[i] != s[i-1]) {
		ll j = i;
		while (j < sz(s) && s[j] == s[i]) j++;
		a.eb(s[i],j-i);
	}
	reverse(all(a));
	
	string t, tc;

	vector<string> res;
	auto print = [&]() {
		ostringstream ss;
		ss << sz(t) << " ";
		if (sz(t) <= 10) {
			FORD(i,0,sz(t)) ss << t[i];
		} else {
			FORD(i,sz(t)-5,sz(t)) ss << t[i];
			ss << "...";
			ss << t[1] << t[0];
		}
		res.pb(ss.str());
	};

	for (auto [c,k]: a) {
		bool bad = sz(t) == 0 || c > t.back() || (c == t.back() && (sz(tc) == 1 || c > tc[sz(tc)-2]));
		if (bad) {
			FOR(i,0,k) {
				if (i%2) t.pop_back();
				else t.pb(c);
				print();
			}
		} else {
			FOR(i,0,k) {
				t.pb(c);
				print();
			}
		}
		if (t.back() == c && tc.back() != c) tc.pb(c);
	}

	reverse(all(res));
	for (string s: res) cout << s << '\n';
}