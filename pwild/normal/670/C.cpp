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
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	map<ll,ll> cnt;
	FOR(i,0,n) cnt[a[i]]++;
	ll m; cin >> m;
	vl b(m), c(m);
	FOR(i,0,m) cin >> b[i];
	FOR(i,0,m) cin >> c[i];
	ll res = -1;
	pll best(-1,-1);
	FOR(i,0,m) {
		pll cur(cnt[b[i]],cnt[c[i]]);
		if (cur > best) best = cur, res = i+1;
	}
	cout << res << endl;





}