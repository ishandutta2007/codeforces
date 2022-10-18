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

bool ch(ll a, ll b, ll c, ll d, ll e, ll f) {
	if (c > a || e > a) return false;
	return d+f <= b;
}

bool check(ll a, ll b, ll c, ll d, ll e, ll f) {
	FOR(i,0,2) {
		FOR(j,0,2) {
			FOR(k,0,2) {
				if (ch(a,b,c,d,e,f)) return true;
				swap(e,f);
			}
			swap(c,d);
		}
		swap(a,b);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, a, b;
	cin >> n >> a >> b;

	vl x(n), y(n);
	FOR(i,0,n) cin >> x[i] >> y[i];

	ll res = 0;
	FOR(i,0,n) FOR(j,i+1,n) if (check(a,b,x[i],y[i],x[j],y[j]))
		res = max(res,x[i]*y[i]+x[j]*y[j]);
	cout << res << endl;
}