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

const ll MOD = 1e9 + 7;

ll fib(ll n) {
	ll a = 0, b = 1;
	while (n--) a += b, swap(a,b), b %= MOD;
	return a;
}

ll solve(string s) {
	for (char c: s) if (c == 'm') return 0;
	for (char c: s) if (c == 'w') return 0;

	ll n = sz(s), res = 1;
	FOR(i,0,n) if (i == 0 || s[i] != s[i-1]) {
		if (s[i] != 'n' && s[i] != 'u') continue;
		ll j = i;
		while (j < n && s[j] == s[i]) j++;
		res = res * fib(j-i+1) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	cout << solve(s) << endl;
}