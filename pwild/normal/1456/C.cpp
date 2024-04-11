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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k;
	cin >> n >> k;
	k++;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a),greater<ll>());

	vl s(n+1);
	FOR(i,0,n) s[i+1] = s[i]+a[i];

	vl w(n);
	FOR(i,0,n) w[i] = i/k;
	reverse(all(w));

	ll cur = 0;
	FOR(i,0,n) cur += a[i]*w[i];

	ll res = cur;
	FOR(i,1,n+1) {
		if (i%k == n%k) continue;
		// cerr << i << endl;
		cur += s[i];
		res = max(res,cur);
	}
	cout << res << endl;
}
// 21100 + s[2]
// 32100 + s[4]
// 43210
//
// 766554433221100 + s[2]
// 876554433221100 + s[4]
// 987654433221100 + s[6]
// A98765433221100
//
// 44333222111000 + s[1]
// 54333222111000 + s[3]
// 65433222111000 + s[4]
// 76543222111000 + s[6]
// 87654322111000 + s[7]
// 98765432111000 + s[9]
// A9876543211000 + s[10]
// BA987654321000