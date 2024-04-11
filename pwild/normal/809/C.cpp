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

const ll MOD = 1e9 + 7;

ll rec(ll x1, ll x2, ll y1, ll y2, ll upper, ll len, ll offs) {
	if (upper <= 0) return 0;

	if (x1 > y1 || (x1 == y1 && x2 < y2)) swap(x1,y1), swap(x2,y2);
	
	if (x1 == 0 && x2 == len) {
		upper = min(upper, len);

		ll sum = ((upper*(upper-1))/2) % MOD;
		
		ll res = ((y2-y1) * ((sum + (offs*upper)%MOD)%MOD)) % MOD;
		return res;
	}
	
	ll res = 0;
	len /= 2;
	if (x1 < len && y1 < len) res += rec(x1, min(x2,len),         y1, min(y2,len),         upper,     len, offs);
	if (x2 > len && y1 < len) res += rec(max(x1-len,0LL), x2-len, y1, min(y2,len),         upper-len, len, offs+len);
	if (x1 < len && y2 > len) res += rec(x1, min(x2,len),         max(y1-len,0LL), y2-len, upper-len, len, offs+len);
	if (x2 > len && y2 > len) res += rec(max(x1-len,0LL), x2-len, max(y1-len,0LL), y2-len, upper,     len, offs);
	return res % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q; cin >> q;
	while (q--) {
		ll x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--, y1--;
		cout << rec(x1,x2,y1,y2,k,1 << 30,1) << "\n";
	}
}