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

bool check(string s) {
	FOR(i,0,sz(s)-1) if (abs(s[i]-s[i+1]) == 1) return false;
	return true;
}

string go(string s) {
	map<char,ll> count;
	for (char c: s) count[c]++;
	
	vector<pair<char,ll>> v(all(count));
	
	if (sz(v) <= 3) {
		do {
			string t;
			FOR(i,0,sz(v)) FOR(j,0,v[i].yy) t += v[i].xx;
			if (check(t)) return t;
		} while (next_permutation(all(v)));
		return "No answer";
	} else {
		string t;
		for (ll i = 1; i < sz(v); i += 2) FOR(j,0,v[i].yy) t += v[i].xx;
		for (ll i = 0; i < sz(v); i += 2) FOR(j,0,v[i].yy) t += v[i].xx;
		assert(check(t));
		return t;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		cout << go(s) << endl;
	}
}