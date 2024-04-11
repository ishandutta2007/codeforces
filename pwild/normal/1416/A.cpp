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
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];

		vl last(n+1,-1), dist(n+1,0);
		FOR(i,0,n) {
			dist[a[i]] = max(dist[a[i]], i-last[a[i]]);
			last[a[i]] = i;
		}
		FOR(x,0,n+1) dist[x] = max(dist[x], n-last[x]);
		
		vl res(n+1,oo);
		FOR(x,0,n+1) res[dist[x]] = min(res[dist[x]],x);

		FOR(k,0,n) res[k+1] = min(res[k+1],res[k]);

		FOR(k,1,n+1) {
			if (res[k] == oo) res[k] = -1;
			cout << res[k] << " \n"[k==n];
		}	
	}
}