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
	
	map<pair<string,string>,ll> cost;

	ll n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;
	
	string cur = "???";
	ll res = 0;	
	FOR(i,0,n) {
		string s, t; cin >> s >> t;
		pair<string,string> p(s,t);
		if (p.xx > p.yy) swap(p.xx,p.yy);
		cost[p] += (s != cur) ? a : b;
		res += (s != cur) ? a : b;
		cur = t;
	}
	
	vl costs;
	for (const auto &q: cost) costs.pb(q.yy);
	sort(all(costs),greater<ll>());
	

	FOR(i,0,min(sz(costs),k)) {
		if (costs[i] > f) res += f-costs[i];
	}
	cout << res << endl;


}