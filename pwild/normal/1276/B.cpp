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

struct bcc { // articulation points = vertices that are in >= 2 components
	ll n, C = 0, T = 0, top = -1;
	vl t, st;
	vvl adj, comps;
	
	ll dfs(ll i, ll p = -1) {
		ll tmin = t[i] = T++;
		st[++top] = i;
		bool first = true;
		for (ll j: adj[i]) {
			if (j == p && first) { first = false; continue; }
			ll ntmin = t[j];
			if (t[j] == -1) {
				ntmin = dfs(j,i);
				if (ntmin >= t[i]) {
					while (st[top] != j) comps[st[top--]].pb(C);
					comps[st[top--]].pb(C);
					comps[i].pb(C++);
				}
			}
			tmin = min(tmin, ntmin);
		}
		return tmin;
	}
	
	bcc(vvl adj): n(sz(adj)), t(n,-1), st(n), adj(adj), comps(n) {
		FOR(i,0,n) if (t[i] < 0) dfs(i);
	}
};

ll solve() {
	ll n, m;
	cin >> n >> m;
	ll s, t;
	cin >> s >> t;
	s--, t--;
	
	vvl adj(n);
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vl parts;
	FOR(dir,0,2) {
		vvl nadj(n);
		FOR(i,0,n) if (i != s) {
			for (ll j: adj[i]) if (j != s) {
				nadj[i].pb(j);
			}
		}
		
		queue<ll> q;
		vb vis(n);

		q.push(t), vis[t] = true;
		
		while (sz(q)) {
			ll i = q.front();
			q.pop();
			for (ll j: nadj[i]) if (!vis[j]) {
				q.push(j), vis[j] = true;				
			}
		}

		ll res = n-1;
		FOR(i,0,n) res -= vis[i];
		parts.pb(res);

		swap(s,t);
	}
	return parts[0] * parts[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		cout << solve() << endl;
	}
}