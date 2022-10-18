#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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

// order statistic tree, change null_type to something else to get a map
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// auto it = s.find_by_order(i); // get i-th element in sorted order
// ll i = s.order_of_key(x); // equivalent to s.lower_bound(x) - begin(s)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vector<pll> b(n);
	FOR(i,0,n) b[i] = {-a[i],i};
	sort(all(b));
	
	ll m; cin >> m;
	vector<tuple<ll,ll,ll>> queries(m);
	FOR(i,0,m) {
		ll k, pos;
		cin >> k >> pos;
		queries[i] = {k,pos,i};
	}
	sort(all(queries));

	ll j = 0;

	vl res(m);
	ordered_set<ll> indices;
	for (auto [k,pos,i]: queries) {
		while (j < k) indices.insert(b[j++].yy);
		res[i] = a[ *indices.find_by_order(pos-1) ];
	}
	
	FOR(i,0,m) cout << res[i] << "\n";
}