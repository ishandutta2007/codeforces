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

const ll M = 255;
ll dp[255][255][255];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q;
	cin >> n >> q;
	
	string w; cin >> w;
	vvl next(n+2,vl(26,n));
	FORD(i,0,n) {
		next[i] = next[i+1];
		next[i][w[i]-'a'] = i;
	}
	
	string a, b, c;
	FOR(i,0,M) FOR(j,0,M) FOR(k,0,M) dp[i][j][k] = n+1;
	dp[0][0][0] = 0;

	auto calc = [&](ll i, ll j, ll k) {
		ll res = oo;
		if (i > 0) res = min(res, next[ dp[i-1][j][k] ][a[i-1]-'a'] + 1);
		if (j > 0) res = min(res, next[ dp[i][j-1][k] ][b[j-1]-'a'] + 1);
		if (k > 0) res = min(res, next[ dp[i][j][k-1] ][c[k-1]-'a'] + 1);
		dp[i][j][k] = res;
	};

	while (q--) {
		char tp;
		ll t;
		cin >> tp >> t;
		
		string &s = t == 1 ? a : (t == 2 ? b : c);
		if (tp == '-') {
			s.pop_back();
		} else {
			char x; cin >> x;
			s.push_back(x);
			
			ll imin = 0, imax = sz(a)+1;
			ll jmin = 0, jmax = sz(b)+1;
			ll kmin = 0, kmax = sz(c)+1;

			if (t == 1) imin = sz(a);
			if (t == 2) jmin = sz(b);
			if (t == 3) kmin = sz(c);

			FOR(i,imin,imax) FOR(j,jmin,jmax) FOR(k,kmin,kmax) calc(i,j,k);
		}
		
		bool res = dp[sz(a)][sz(b)][sz(c)] <= n;
		//TR(dp[sz(a)][sz(b)][sz(c)]);
		cout << (res ? "YES" : "NO") << endl;
	}







}