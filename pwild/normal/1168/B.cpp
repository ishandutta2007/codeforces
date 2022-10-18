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

bool has_hit(string s) {
	ll n = sz(s);
	FOR(i,0,n) FOR(k,1,n) {
		if (i+2*k >= n) break;
		if (s[i] == s[i+k] && s[i] == s[i+2*k]) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	set<ll> no_hits;
	FOR(n,1,12) FOR(mask,0,1 << n) {
		string s(n,'0');
		FOR(i,0,n) if (mask & (1 << i)) s[i] = '1';
		if (!has_hit(s)) {
			ll x = 0;
			FOR(i,0,n) x = 3*x + s[i]-'0' + 1;
			no_hits.insert(x);
		}
	}
	
	string s; cin >> s;
	ll n = sz(s), res = n*(n+1)/2;
	FOR(i,0,n) {
		ll x = 0;
		FOR(j,i,min(i+10,n)) {
			x = 3*x + s[j]-'0' + 1;
			if (no_hits.count(x)) res--;
			//else cerr << i << " " << j << endl;
		}
	}
	cout << res << endl;
}