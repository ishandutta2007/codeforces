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
	
	string s; cin >> s;
	vector<string> v;
	ll i = 0;
	while (i < sz(s)) {
		while (s[i] >= 'a' && s[i] <= 'z') i++;
		ll j = i;
		while (j < sz(s) && (s[j] < 'a' || s[j] > 'z')) j++;
		v.pb(s.substr(i,j-i));
		i = j;
	}
	ll res = 0;
	bool frac = false;
	for (string t: v) {
		ll n = sz(t);
		bool curfrac = (n > 3 && t[n-3] == '.');
		ll cur = 0;
		FOR(i,0,n) if (t[i] != '.') cur = 10*cur + t[i]-'0';
		if (!curfrac) cur *= 100;
//		cerr << cur << endl;
		if (curfrac) frac = true;
		res += cur;
	}
	frac = res % 100 != 0;
	string d;
	while (res) d.pb(res%10 + '0'), res /= 10;
	if (frac) {
		while (sz(d) < 3) d.pb('0');
	}
	reverse(all(d));
	ll n = sz(d);
	if (frac) {
		FOR(i,0,n) {
			cout << d[i];
			if ((n-3-i) % 3 == 0) cout << ".";
		}
	} else {
		FOR(i,0,n-2) {
			cout << d[i];
			if (i < n-3 && (n-3-i) % 3 == 0) cout << ".";
		}
	}
	cout << endl;
}