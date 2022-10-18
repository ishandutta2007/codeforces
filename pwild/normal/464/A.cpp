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
	
	ll n, p; cin >> n >> p;
	string s; cin >> s;
	
	auto ok = [&](ll i, char c) {
		if (i-1 >= 0 && s[i-1] == c) return false;
		if (i-2 >= 0 && s[i-2] == c) return false;
		return true;
	};
	FORD(i,0,n) {
		for (char c = s[i]+1; c < 'a'+p; c++) if (ok(i,c)) {
			s[i] = c;
			for (ll j = i+1; j < n; j++) {
				s[j] = 'a';
				while (!ok(j,s[j])) s[j]++;
				assert(s[j] < 'a'+p);
			}
			cout << s << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}