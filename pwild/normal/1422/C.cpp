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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	ll n = sz(s);

	vl a(n);
	FOR(i,0,n) a[i] = s[i]-'0';

	vl p10(n+1), suf(n+1);
	p10[0] = 1;
	FOR(k,1,n+1) p10[k] = 10*p10[k-1] % MOD;
	FORD(k,0,n) suf[k] = (p10[n-1-k]*a[k] + suf[k+1]) % MOD;

	ll pref = 0, sumpref = 0, res = 0;
	FOR(k,1,n+1) {
		res = (res + sumpref*p10[n-k] + k*suf[k]) % MOD;
		pref = (10*pref + a[k-1]) % MOD;
		sumpref = (sumpref + pref) % MOD;
	}
	cout << res << endl;
}