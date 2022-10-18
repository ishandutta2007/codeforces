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

bool is_vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<string> v(n);
	FOR(i,0,n) cin >> v[i];
	
	map<pll,vl> words;
	FOR(i,0,n) {
		ll count = 0;
		char last = 'x';
		for (char c: v[i]) if (is_vowel(c)) {
			count++;
			last = c;
		}
		pll pr(count,last);
		words[pr].pb(i);
	}
	
	vector<pll> pairs;
	map<ll,vl> words2;
	for (const auto &pr: words) {
		const vl &a = pr.yy;
		FOR(i,0,sz(a)/2) {
			pairs.eb(a[2*i],a[2*i+1]);
		}
		if (sz(a)%2) words2[pr.xx.xx].pb(a.back());
	}
	
	vector<pll> pairs2;
	for (const auto &pr: words2) {
		const vl &a = pr.yy;
		FOR(i,0,sz(a)/2) {
			pairs2.eb(a[2*i],a[2*i+1]);
		}
	}

	while (sz(pairs) > sz(pairs2)) {
		pairs2.pb(pairs.back());
		pairs.pop_back();
	}
	
	cout << sz(pairs) << endl;
	FOR(i,0,sz(pairs)) {
		ll a, b, c, d;
		tie(b,d) = pairs[i];
		tie(a,c) = pairs2[i];
		cout << v[a] << " " << v[b] << "\n";
		cout << v[c] << " " << v[d] << "\n";
	}
}