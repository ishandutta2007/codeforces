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

string unrank(vector<string> a, ll rk) {
	ll n = sz(a), m = sz(a[0]);
	ll lo = 0, hi = n;
	string res;
	FOR(i,0,m) {
		ll mid = lo;
		while (mid < hi && a[mid][i] == '0') mid++;

		ll cntL = (1LL << (m-1-i)) - (mid-lo);
		if (rk < cntL) {
			res.pb('0');
			hi = mid;
		} else {
			res.pb('1');
			rk -= cntL;
			lo = mid;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	vector<string> b = {"000","011","100","111"};
//	FOR(i,0,4) cout << unrank(b,i) << endl;
//	return 0;

	ll tc; cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;

		vector<string> a(n);
		FOR(i,0,n) cin >> a[i];
		sort(all(a));

		ll rk = ((1LL << m) - n - 1) / 2;
		cout << unrank(a, rk) << endl;
	}

}