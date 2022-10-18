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
	vector<pll> a(n);	
	FOR(i,0,n) cin >> a[i].xx;
	FOR(i,0,n) cin >> a[i].yy;
	
	vl cnt(201);
	FOR(i,0,n) cnt[a[i].yy]++;

	sort(all(a),greater<pll>());
	
	ll basecost = 0;
	ll best = oo;
	ll i = 0;
	while (i < n) {
		ll len = a[i].xx;
		ll j = i;
		while (j < n && a[j].xx == len) {
			cnt[a[j].yy]--;
			j++;
		}
		ll cost = basecost;
		ll keep = j-i-1;
		ll take = max(0LL,n-j-keep);
		FOR(k,1,201) {
			if (!take) break;
			ll takehere = min(take,cnt[k]);
			take -= takehere;
			cost += takehere*k;
		}
		best = min(best,cost);
		j = i;
		while (j < n && a[j].xx == len) {
			basecost += a[j].yy;
			j++;
		}
		i = j;
	}
	cout << best << endl;

}