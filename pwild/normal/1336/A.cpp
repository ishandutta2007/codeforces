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

const ll N = 200100;
vl adj[N];
ll dist[N], sub[N];

void dfs(ll i) {
	for (ll j: adj[i]) if (dist[j] == oo) {
		dist[j] = dist[i] + 1;
		dfs(j);
		sub[i] += sub[j];
	}
	sub[i]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	FOR(i,1,n) {
		ll a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;

	dfs(1);
	
	vl is(n);
	iota(all(is),1);
	sort(all(is), [&](ll i, ll j) {
		return dist[i]-sub[i] > dist[j]-sub[j];
	});
	is.resize(k);

	ll res = k;
	for (ll i: is) res += dist[i]-sub[i];
	cout << res << endl;
}