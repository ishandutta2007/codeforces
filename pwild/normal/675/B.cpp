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
	
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	ll res = 0;
	FOR(x,1,n+1) {
		ll ymin = max(max(1LL,c-b+1),max(d-a+1,c+d-a-b+1));
		ll ymax = min(min(n  ,c-b+n),min(d-a+n,c+d-a-b+n));
		if (ymin <= ymax) res += ymax-ymin+1;
	}
	cout << res << endl;
}