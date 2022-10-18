#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

const ll MAGIC = 700;

struct query {
	ll a, b, i;
	bool operator<(const query &q) {
		if (a/MAGIC != q.a/MAGIC) return a < q.a;
		return b < q.b; //((a/MAGIC) & 1) ? b < q.b : b > q.b;
	}
};

const int N = 2e5 + 10;
int freq[N], val[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q; cin >> n >> q;
	vl x(n);
	FOR(i,0,n) cin >> x[i];
	
	map<ll,ll> id;
	ll K = 0;
	FOR(i,0,n) {
		if (!has(id,x[i])) id[x[i]] = K++;
		val[id[x[i]]] = x[i];
		x[i] = id[x[i]];
	}
	
	vector<query> queries(q);
	FOR(i,0,q) cin >> queries[i].a >> queries[i].b, queries[i].a--, queries[i].i = i;
	sort(all(queries));
	
	long long sum = 0;
	ll a = 0, b = 0;
	
	auto add = [&](ll i) {
		sum += (long long)(2*freq[x[i]]+1)*val[x[i]];
		freq[x[i]]++;
	};
	auto sub = [&](ll i) {
		sum -= (long long)(2*freq[x[i]]-1)*val[x[i]];
		freq[x[i]]--;
	};

	vector<long long> res(q);

	for (const auto &q: queries) {
		while (b < q.b) add(b++);
		while (a > q.a) add(--a);
		while (b > q.b) sub(--b);
		while (a < q.a) sub(a++);
		res[q.i] = sum;
	}
	FOR(i,0,q) cout << res[i] << "\n";
}