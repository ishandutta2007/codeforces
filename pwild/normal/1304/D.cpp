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

void solve() {
	ll n; cin >> n;
	string s; cin >> s;

	vvl adj(n);
	FOR(i,0,n-1) {
		if (s[i] == '<') adj[i].pb(i+1);
		else adj[i+1].pb(i);
	}
	
	for (ll sign: {-1,1}) {
		vl indeg(n);
		FOR(i,0,n) for (ll j: adj[i]) indeg[j]++;

		set<ll> q;
		FOR(i,0,n) if (!indeg[i]) q.insert(sign*i);
		
		vl res(n);
		FOR(k,0,n) {
			ll i = abs(*begin(q));
			q.erase(begin(q));
			res[i] = k+1;
			
			for (ll j: adj[i]) if (!--indeg[j]) {
				q.insert(sign*j);
			}
		}
		
		FOR(i,0,n) cout << res[i] << " \n"[i+1==n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}