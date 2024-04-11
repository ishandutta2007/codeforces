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

	set<pll> edges;
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		edges.emplace(a,b);
		edges.emplace(b,a);
	}
	
	vl col(n,-1);
	set<ll> todo;
	FOR(i,0,n) todo.insert(i);
	
	ll C = 0;
	while (sz(todo)) {
		ll s = *begin(todo);
		todo.erase(s);

		queue<ll> q;
		q.push(s), col[s] = C;
		while (sz(q)) {
			ll i = q.front();
			q.pop();
			for (auto it = begin(todo); it != end(todo);) {
				ll j = *it;
				if (edges.count(mp(i,j))) {
					it++;
				} else {
					it = todo.erase(it);
					col[j] = col[i];
					q.push(j);
				}
			}
		}
		C++;
	}
	cout << C-1 << endl;
}