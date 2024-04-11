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

ll solve(vl a) {
	ll n = sz(a), res = 0;
	FOR(i,0,n) FOR(j,i,n) FOR(k,j,n) res = max(res, a[i] | a[j] | a[k]);
	return res;
}

const ll K = 60;

ll brute(vl a) {
	ll n = sz(a), res = 0;
	FOR(mask,1,1 << n) {
		ll k = __builtin_popcount(mask);
		vl cnt(K);
		FOR(i,0,n) if (mask & (1 << i)) {
			FOR(j,0,K) if (a[i] & (1LL << j)) cnt[j]++;
		}
		ll cur = 0;
		FOR(j,0,K) if (cnt[j] >= max(1LL,k-2)) cur += 1LL << j;
		res = max(res,cur);
	}
	return res;
}

void test() {
	FOR(i,0,1000) {
		ll n = 1 + rand() % 15;
		vl a(n);
		FOR(i,0,n) a[i] = rand();
		assert(solve(a) == brute(a));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	test();
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	cout << solve(a) << endl;
}