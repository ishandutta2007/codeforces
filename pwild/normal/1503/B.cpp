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
	
	ll n; cin >> n;
	vector<vector<pll>> a(2);
	FOR(i,0,n) FOR(j,0,n) a[(i+j)%2].eb(i,j);
	
	FOR(k,0,n*n) {
		ll ban; cin >> ban; ban--;

		auto go = [&](ll bucket) {
			ll pick = bucket;
			if (pick == ban) pick = 2;
			auto [i,j] = a[bucket].back();
			a[bucket].pop_back();
			cout << pick+1 << " " << i+1 << " " << j+1 << endl;
		};

		if (ban != 0 && sz(a[0])) go(0);
		else if (ban != 1 && sz(a[1])) go(1);
		else if (sz(a[0])) go(0);
		else go(1);
	}
}