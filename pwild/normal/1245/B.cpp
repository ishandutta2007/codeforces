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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n, R, P, S;
		cin >> n >> R >> P >> S;
		
		string s; cin >> s;
		string t(n,'?');

		ll res = 0;
		FOR(i,0,n) {
			if (s[i] == 'R' && P > 0) t[i] = 'P', P--, res++;
			if (s[i] == 'P' && S > 0) t[i] = 'S', S--, res++;
			if (s[i] == 'S' && R > 0) t[i] = 'R', R--, res++;
		}
		FOR(i,0,n) {
			if (t[i] == '?' && P > 0) t[i] = 'P', P--;
			if (t[i] == '?' && S > 0) t[i] = 'S', S--;
			if (t[i] == '?' && R > 0) t[i] = 'R', R--;
		}

		if (2*res >= n) {
			cout << "YES" << endl << t << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}