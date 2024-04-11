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
	
	ll n, m;
	cin >> n >> m;

	map<ll,ll> dist;
	queue<ll> q;

	FOR(i,0,n) {
		ll x; cin >> x;
		dist[x] = 0;
		q.push(x);
	}
	
	vl res;
	while (sz(res) < m) {
		ll x = q.front();
		q.pop();
		FOR(dx,-1,2) if (dx) {
			ll nx = x+dx;
			if (dist.count(nx)) continue;
			dist[nx] = dist[x]+1;
			q.push(nx);
			res.pb(nx);
		}
	}
	res.resize(m);
	
	ll ans = 0;
	for (ll x: res) ans += dist[x];
	
	cout << ans << endl;
	for (ll x: res) cout << x << " ";
	cout << endl;
}