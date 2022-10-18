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

const ll N = 1e5 + 10, MOD = 1e9 + 7;
string glue;
ll p2[N], dp[N][26];

ll rec(ll j, ll k, string s) {
	ll n = sz(s);
	if (n == 0) return p2[k-j];
	if (j == k) return 0;
	if (n == 1) {
		ll c = s[0]-'a';
		return (dp[k][c] - p2[k-j]*dp[j][c]) % MOD;
	}
	
	string t, u;
	FOR(i,0,n) (i%2 ? u : t).pb(s[i]);
	
	bool okt = true, oku = true;
	for (char c: t) if (c != glue[j]) okt = false;
	for (char c: u) if (c != glue[j]) oku = false;

	ll res = 0;
	if (okt) res += rec(j+1,k,u);
	if (oku) res += rec(j+1,k,t);
	res %= MOD;
	return res;
}

ll solve(ll k, const string &s) {
//	cerr << "   " << k << " " << s << endl;
	return rec(0,k,s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	p2[0] = 1;
	FOR(n,1,N) p2[n] = 2*p2[n-1] % MOD;
	
	ll n, q;
	cin >> n >> q;

	string base;
	cin >> base >> glue;
	ll jump = sz(base)+1;
	
	FOR(i,0,n) {
		FOR(j,0,26) dp[i+1][j] = 2*dp[i][j] % MOD;
		dp[i+1][glue[i]-'a']++;
	}

	while (q--) {
		ll k; cin >> k;
		string s; cin >> s;
		ll m = sz(s);
		
		vl same_jumps(m);
		FORD(i,0,m) {
			same_jumps[i] = i+jump >= m || (s[i] == s[i+jump] && same_jumps[i+jump]);
		}

		ll res = 0;
		FOR(offset,0,jump) { // offset = position of first ? in s
			string oth;
			for (ll i = offset; i < m; i += jump) oth.pb(s[i]);
			bool ok = true;
			FOR(j,0,min(m,jump)) {
				if (j == offset) continue;
				if (!same_jumps[j]) ok = false;
				if (j < offset && s[j] != base[sz(base) - (offset-j)]) ok = false;
				if (j > offset && s[j] != base[j-offset-1]) ok = false;
				if (!ok) break;
			}
			if (ok) res += solve(k,oth);
		}
		res %= MOD;
		if (res < 0) res += MOD;
		cout << res << endl;
	}
}