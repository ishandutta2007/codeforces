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
	
	vl a = {4,8,15,16,23,42};
	map<ll,ll> b;
	FOR(i,0,6) b[a[i]] = i;

	ll n; cin >> n;
	vl cnt(7);
	cnt[0] = n;
	FOR(i,0,n) {
		ll x; cin >> x;
		x = b[x];
		if (cnt[x]) cnt[x]--, cnt[x+1]++;
	}
	cout << n-6*cnt[6] << endl;
}