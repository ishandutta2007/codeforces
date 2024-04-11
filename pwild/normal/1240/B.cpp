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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];

		vl b = a;
		sort(all(b));
		b.erase(unique(all(b)),end(b));
		map<ll,ll> bi;
		FOR(i,0,sz(b)) bi[b[i]] = i;

		FOR(i,0,n) a[i] = bi[a[i]];

		ll m = sz(b);
		vl left(m,n), right(m,-1);
		FOR(i,0,n) {
			left[a[i]] = min(left[a[i]], i);
			right[a[i]] = max(right[a[i]], i);
		}
		
		ll res = 1, cur = 1;
		FOR(k,1,m) {
			if (right[k-1] < left[k]) {
				cur++;
			} else {
				cur = 1;
			}
			res = max(res,cur);
		}
		
		res = m-res;
		cout << res << endl;
	}
}