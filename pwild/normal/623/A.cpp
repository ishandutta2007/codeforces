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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	vector<set<ll>> adj(n);
	FOR(i,0,n) FOR(j,0,n) if (i != j) adj[i].insert(j);
	FOR(i,0,m) {
		ll a, b; cin >> a >> b;
		a--, b--;
		adj[a].erase(b);
		adj[b].erase(a);
	}
	

	string col(n,'b');
	FOR(i,0,n) if (sz(adj[i])) {
		queue<ll> q;
		col[i] = 'a';
		q.push(i);
		while (sz(q)) {
			ll a = q.front(); q.pop();
			for (ll b: adj[a]) {
				if (col[b] == col[a]) {
					cout << "No" << endl;
					return 0;
				}
				if (col[b] == 'b') {
					col[b] = (col[a] == 'a' ? 'c' : 'a');
					q.push(b);
				}
			}
		}
		break;
	}
	FOR(i,0,n) if (col[i] == 'b' && sz(adj[i])) {
		cout << "No" << endl;
		return 0;
	}
	FOR(i,0,n) FOR(j,0,n) if (col[i] == 'a' && col[j] == 'c' && !has(adj[i],j)) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << col << endl;
}