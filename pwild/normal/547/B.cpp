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

const ll maxN = 200010;

ll a[maxN], id[maxN], par[maxN], h[maxN], w[maxN], res[maxN];
bool mark[maxN];

ll Find(ll x) {
	if (x != par[x]) par[x] = Find(par[x]);
	return par[x];
}

bool Union(ll x, ll y) {
	if ((x = Find(x)) == (y = Find(y))) return false;
	if (h[x] > h[y]) swap(x,y);
	par[x] = y;
	w[y] += w[x];
	if (h[x] == h[y]) h[y]++;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	
	FOR(i,0,n) id[i] = i;
	sort(id,id+n,[&](const ll &x, const ll &y) {
		return a[x] > a[y];
	});
	
	FOR(i,0,n) par[i] = i, h[i] = 0, w[i] = 1, mark[i] = false;
	FOR(i,0,n) res[i] = 0;

	FOR(j,0,n) {
		ll i = id[j];
		mark[i] = true;
		if (i > 0 && mark[i-1]) Union(i,i-1);
		if (i < n-1 && mark[i+1]) Union(i,i+1);
		ll x = w[Find(i)];
		res[x] = max(res[x],a[i]);
	}

	FORD(i,1,n) res[i] = max(res[i],res[i+1]);

	FOR(i,1,n) cout << res[i] << " ";
	cout << res[n] << endl;

}