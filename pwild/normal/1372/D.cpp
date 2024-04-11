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
	
	ll n; cin >> n;

	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vl b(2*n);
	FOR(i,0,2*n) b[i] = a[(2*i)%n];
	
	ll res = 0, cur = 0, k = n/2+1;
	FOR(i,0,k) cur += b[i];
	FOR(i,k,2*n) {
		res = max(res,cur);
		cur += b[i]-b[i-k];
	}
	
	cout << res << endl;
}