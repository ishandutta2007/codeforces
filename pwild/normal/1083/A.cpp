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

vl w;
vector<vector<pll>> adj;
ll res = 0;

ll dfs(ll i, ll p) {
	ll best1 = 0, best2 = 0;
	for (auto e: adj[i]) {
		if (e.xx == p) continue;
		ll cur = dfs(e.xx,i)-e.yy;
		if (cur > best1) best2 = best1, best1 = cur;
		else if (cur > best2) best2 = cur;
	}
	res = max(res, w[i]+best1+best2);
	return w[i]+best1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	w.resize(n);
	adj.resize(n);
	FOR(i,0,n) cin >> w[i];
	FOR(i,1,n) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].eb(b,c);
		adj[b].eb(a,c);
	}

	dfs(0,-1);
	cout << res << endl;

}