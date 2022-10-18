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

bool subseq(const string &a, const string &b) {
	ll m = sz(a), n = sz(b);
	ll i = 0, j = 0;
	while (i < m && j < n) if (a[i] == b[j++]) i++;
	return i == m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	
	for (ll i = 0; i < 1000; i += 8) {
		stringstream ss;
		ss << i;
		string t = ss.str();
		if (subseq(t,s)) {
			cout << "YES" << endl;
			cout << t << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}