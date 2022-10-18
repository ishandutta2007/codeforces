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
	ll n, x;
	cin >> n >> x;

	string a; cin >> a;
	
	ll d = 0;
	map<ll,ll> cnt;
	for (char c: a) {
		cnt[d]++;
		d += c == '0' ? 1 : -1;
	}
	
	ll res = 0;
	for (auto [b,k]: cnt) {
		// b + i*d == x
		ll y = x-b;
		if (d == 0) {
			if (x == b) {
				cout << -1 << endl;
				return;
			}
		} else {
			if (y%d) continue;
			if (y/d >= 0) res += k;
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}