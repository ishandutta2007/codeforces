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
	
	string s, t;
	cin >> s >> t;
	
	vl sc(26), tc(26);
	ll qc = 0;
	for (char c: s) if (c == '?') qc++; else sc[c-'a']++;
	for (char c: t) tc[c-'a']++;
	
	string r(qc,'a');
	ll j = 0;

	FOR(cnt,0,2e6) {
		if (j >= qc) break;

		FOR(k,0,26) if (sc[k] < cnt*tc[k]) {
			ll x = cnt*tc[k] - sc[k];
			FOR(i,0,x) {
				if (j >= qc) break;
				r[j++] = 'a'+k;
				sc[k]++;
			}
		}
	}
	j = 0;
	for (char &c: s) if (c == '?') c = r[j++];
	cout << s << endl;
}