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
	vl p(n);
	FOR(i,0,n) cin >> p[i];
	
	vl index_of(n+1);
	FOR(i,0,n) index_of[p[i]] = i;
	
	set<ll> bounds = {-1LL,n};
	
	ll res = 0;
	FORD(a,1,n+1) {
		ll k = index_of[a];
		auto it = bounds.lower_bound(k);
		ll i = *prev(it), j = *it;
		bounds.insert(k);
		
		if (k-i < j-k) {
			FOR(t,i+1,k) {
				ll b = p[t], c = a-b;
				if (index_of[c] > k && index_of[c] < j) res++;
			}
		} else {
			FOR(t,k+1,j) {
				ll b = p[t], c = a-b;
				if (index_of[c] > i && index_of[c] < k) res++;
			}
		}
	}
	cout << res << endl;
}