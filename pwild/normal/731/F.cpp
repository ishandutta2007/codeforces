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
	vl s(n+1);
	FOR(i,0,n) s[i+1] = s[i] + a[i];
	
	sort(all(a));	
	ll m = 200010;
	vl lb(m);
	{
		ll j = 0;
		FOR(i,0,m) {
			while (j < n && a[j] < i) j++;
			lb[i] = j;
		}
	}
//	FOR(i,0,20) cout << i << " " << lb[i] << endl;
	
	ll res = oo;
	FOR(i,0,n) if (i == 0 || a[i] > a[i-1]) {
		ll x = a[i], cur = 0;
		for (ll y = 0; y < m; y += x) {
			ll z = min(y+x,m-1);
			ll l = lb[y], r = lb[z];
			cur += (s[r]-s[l]) - y*(r-l);
		}
		res = min(res,cur);
	}
	res = s[n] - res;
	cout << res << endl;
}