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

bool solve(string a) {
	ll ds = 0;
	for (char c: a) ds += c-'0';
	if (ds%3) return false;

	vl cnt(10);
	for (char c: a) cnt[c-'0']++;
	
	ll even = 0;
	FOR(i,0,5) even += cnt[2*i];
	return even >= 2 && cnt[0] >= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		string a; cin >> a;
		cout << (solve(a) ? "red" : "cyan") << endl;
	}
}