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

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<pll,ll> id;
	ll n = 0, m;
	cin >> m;
	
	auto get_id = [&](ll z, bool isx) {
		pll p(z,isx);
		if (!id.count(p)) id[p] = n++;
		return id[p];
	};

	vvl adj(2*m);

	FOR(k,0,m) {
		ll x, y;
		cin >> x >> y;
		ll i = get_id(x,true);
		ll j = get_id(y,false);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	adj.resize(n);
	
	ll C = 0;
	vl comp(n,-1);
	FOR(s,0,n) if (comp[s] == -1) {
		queue<ll> q;
		q.push(s);
		comp[s] = C;
		while (sz(q)) {
			ll i = q.front();
			q.pop();
			for (ll j: adj[i]) if (comp[j] == -1) {
				q.push(j);
				comp[j] = C;
			}
		}
		C++;
	}
	
	vl vcnt(C), ecnt(C);
	FOR(i,0,n) {
		ll c = comp[i];
		vcnt[c]++;
		ecnt[c] += sz(adj[i]);
	}
	
	ll res = 1;
	FOR(c,0,C) {
		ecnt[c] /= 2;
		ll cur = 1;
		FOR(i,0,vcnt[c]) cur = 2*cur % MOD;
		if (ecnt[c] == vcnt[c]-1) cur = (cur+MOD-1) % MOD;
		res = res*cur % MOD;
	}
	cout << res << endl;
}