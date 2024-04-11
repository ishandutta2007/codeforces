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
	map<ll,ll> cnt;
	FOR(i,0,n) {
		ll x; cin >> x;
		cnt[x]++;
	}

	vl sum(n+1);
	for (auto [x,c]: cnt) {
		FOR(i,1,c+1) sum[i]++;
	}
	FOR(i,1,n+1) sum[i] += sum[i-1];
//	FOR(i,1,n+1) cout << sum[i] << " \n"[i==n];


	vl d(n+1);
	FORD(x,1,n+1) for (ll y = x*x; y <= n; y += x) {
		if (d[y] == 0) d[y] = x;
	}
	// FOR(i,1,n+1) cout << i << " " << d[i] << endl;
	
	FORD(x,1,n+1) {
		ll h = d[x], w = x/h;
		bool ok = sum[h] >= x;
		if (!ok) continue;

		vector<pll> pairs;
		for (auto [x,c]: cnt) pairs.eb(min(c,h),x);
		sort(all(pairs),greater<pll>());

		vvl res(h,vl(w,-1));
		ll i = 0, j = 0;
		for (auto [c,x]: pairs) {
			while (c--) {
				res[i][(i+j)%w] = x;
				i++;
				if (i == h) i = 0, j++;
			}
		}
		
		cout << x << endl;
		cout << h << " " << w << endl;
		FOR(i,0,h) FOR(j,0,w) cout << res[i][j] << " \n"[j+1==w];
		return 0;
	}
}