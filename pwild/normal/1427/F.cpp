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
	
	ll n; cin >> n;

	vl col(6*n,1);
	FOR(i,0,3*n) {
		ll x; cin >> x;
		col[x-1] = 0;
	}

	vvl group;
	vl parent;
	stack<ll> st;
	FOR(i,0,6*n) {
		if (st.empty() || col[group[st.top()][0]] != col[i]) {
			parent.pb(st.empty() ? -1 : st.top());
			st.push(sz(group));
			group.pb({i});
		} else {
			group[st.top()].pb(i);
			if (sz(group[st.top()]) == 3) st.pop();
		}
	}
	
	vl indeg(2*n);
	FOR(i,0,2*n) if (parent[i] != -1) indeg[parent[i]]++;

	FOR(i,0,n) {
		bool found = false;
		auto take = [&](ll j) {
			for (ll x: group[j]) cout << x+1 << " ";
			cout << endl;
			found = true;
			indeg[j] = oo;
			if (parent[j] != -1) indeg[parent[j]]--;
		};
		FOR(j,0,2*n) if (!found && col[group[j][0]] == 0 && indeg[j] == 0) take(j);
		assert(found);
		found = false;
		FOR(j,0,2*n) if (!found && col[group[j][0]] == 1 && indeg[j] == 0 && parent[j] != -1) take(j);
		FOR(j,0,2*n) if (!found && col[group[j][0]] == 1 && indeg[j] == 0) take(j);
		assert(found);
	}
}