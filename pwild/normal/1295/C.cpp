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

void solve() {
	string s, t;
	cin >> s >> t;
	
	ll n = sz(s);
	s += s;
	vvl next(2*n+1,vl(26,2*n));
	FORD(i,0,2*n) {
		next[i] = next[i+1];
		ll j = s[i]-'a';
		next[i][j] = i;
	}
	
	ll res = 0, i = 0;
	for (char c: t) {
		ll j = next[i][c-'a']+1;
		if (j > 2*n) {
			cout << -1 << endl;
			return;
		}
		if (j >= n) j -= n, res++;
		i = j;
	}
	
	if (i > 0) res++;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}