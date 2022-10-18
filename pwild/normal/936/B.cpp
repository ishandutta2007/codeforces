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
	vvl adj(n), revadj(n);
	FOR(i,0,n) {
		ll k; cin >> k;
		while (k--) {
			ll j; cin >> j;
			j--;
			adj[i].pb(j);
			revadj[j].pb(i);
		}
	}
	
	vector<vl> dist(2,vl(n,oo));
	queue<pll> Q;
	FOR(i,0,n) if (!sz(adj[i])) {
		dist[0][i] = 0;
		Q.emplace(0,i);
	}
	
	while (sz(Q)) {
		ll d, i;
		tie(d,i) = Q.front();
		Q.pop();
		
		for (ll j: revadj[i]) {
			if (dist[1-d][j] < oo) continue;
			dist[1-d][j] = dist[d][i] + 1;
			Q.emplace(1-d,j);
		}
	}
	

	vl outdeg(n);
	FOR(i,0,n) outdeg[i] = sz(adj[i]);
	
	vb reachcycle(n,true);
	FOR(i,0,n) if (!outdeg[i]) {
		reachcycle[i] = false;
		Q.emplace(0,i);
	}

	while (sz(Q)) {
		ll i = Q.front().yy;
		Q.pop();

		for (ll j: revadj[i]) {
			if (!--outdeg[j]) {
				reachcycle[j] = false;
				Q.emplace(0,j);
			}
		}
	}

	ll s; cin >> s;
	s--;

	if (dist[1][s] < oo) {
		cout << "Win" << endl;
		ll d = 1, i = s;
		while (sz(adj[i])) {
			cout << i+1 << " ";
			for (ll j: adj[i]) if (dist[1-d][j] < dist[d][i]) {
				d = 1-d, i = j;
				break;
			}
		}
		cout << i+1 << endl;
	} else {
		cout << (reachcycle[s] ? "Draw" : "Lose") << endl;
	}

}