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

const ll N = 2e6, MOD = 1e9 + 7;
ll r;
vector<pll> adj[N];

void add_path(ll a, ll b, ll k) {
	if (k < 10) {
		adj[a].pb({k,b});
	} else {
		vl digits;
		for (; k; k /= 10) digits.pb(k%10);
		reverse(all(digits));
		adj[a].pb({digits[0],r});
		FOR(i,1,sz(digits)-1) adj[r].pb({digits[i],r+1}), r++;
		adj[r++].pb({digits.back(),b});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	r = n;

	FOR(k,1,m+1) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		add_path(a,b,k);
		add_path(b,a,k);
	}
	
	vl dist(r,oo);
	queue<vl> q;
	dist[0] = 0;
	q.push({0});
	
	while (sz(q)) {
		vl v = q.front();
		q.pop();
		
		map<ll,ll> best;
		for (ll i: v) for (auto [d,j]: adj[i]) {
			if (dist[j] != oo) continue;
			if (!best.count(j)) best[j] = 10;
			best[j] = min(best[j],d);
		}

		vvl ws(10);
		ll i = v[0];
		for (auto [j,d]: best) {
			dist[j] = (10*dist[i] + d) % MOD;
			ws[d].pb(j);
		}
		for (auto w: ws) if (sz(w)) q.push(w);
	}
	
	FOR(i,1,n) cout << dist[i] << "\n";
}