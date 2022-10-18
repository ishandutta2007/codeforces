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

ll eval(string s) {
	ll res = 0;
	ll n = sz(s);
	ll prv = 0;
	ll i = 0;
	while (i < n) {
		if (s[i] == '*') {
			i++;
			ll cur = 0;
			while (s[i] >= '0' && s[i] <= '9') cur = 10*cur + s[i++]-'0';
			prv *= cur;
		} else if (s[i] == '+') {
			i++;
			ll cur = 0;
			while (s[i] >= '0' && s[i] <= '9') cur = 10*cur + s[i++]-'0';
			res += prv;
			prv = cur;
		} else exit(1);
	}
	res += prv;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	
	stringstream ss(s);
	string h;
	vector<string> t;
	while (getline(ss,h,'*')) t.pb(h);
	
	ll k = sz(t);

	ll best = eval("+"+s);
	FOR(l,0,k) FOR(r,l+1,k+1) {
		string h = "+";
		FOR(i,l,r) {
			h += t[i];
			if (i < r-1) h += "*";
		}
		ll br = eval(h);
		stringstream st;
		st << '+';
		FOR(i,0,l) st << t[i] << '*';
		st << br;
		FOR(i,r,k) st << '*' << t[i];
		h = st.str();
		//cerr << h << endl;
		best = max(best,eval(h));	
	}
	cout << best << endl;

}