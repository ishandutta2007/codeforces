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
	
	ll m, n;
	cin >> m >> n;
	
	vl acnt(2), bcnt(2);
	
	while (m--) {
		ll x; cin >> x;
		acnt[x%2]++;
	}
	while (n--) {
		ll x; cin >> x;
		bcnt[x%2]++;
	}
	
	ll res = 0;
	FOR(k,0,2) res += min(acnt[k],bcnt[1-k]);
	cout << res << endl;


}