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

bool ab[100010], ba[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;

	ll n = sz(s);
	memset(ab,0,sizeof(ab));
	memset(ba,0,sizeof(ba));

	FOR(i,2,n+1) {
		ab[i] = ab[i-1], ba[i] = ba[i-1];
		if (s[i-2] == 'A' && s[i-1] == 'B') {
			if (ba[i-2]) {
				cout << "YES" << endl;
				return 0;
			}
			ab[i] = true;
		}
		if (s[i-2] == 'B' && s[i-1] == 'A') {
			if (ab[i-2]) {
				cout << "YES" << endl;
				return 0;
			}
			ba[i] = true;
		}
	}
	
	cout << "NO" << endl;
	
}