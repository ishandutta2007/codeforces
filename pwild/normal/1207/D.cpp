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

const ll MOD = 998244353;

ll factorial(ll n) {
	ll res = 1;
	FOR(i,1,n+1) res = res*i % MOD;
	return res;
}

template<typename F>
ll count_permutations(vector<pll> a, F f) {
	sort(all(a),[&](pll p, pll q) { return f(p) < f(q); });
	ll res = 1, count = 1;
	FOR(i,0,sz(a)) {
		if (i == 0 || f(a[i]) != f(a[i-1])) {
			res = res * factorial(count) % MOD;
			count = 0;
		}
		count++;
	}
	res = res * factorial(count) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<pll> a(n);
	FOR(i,0,n) cin >> a[i].xx >> a[i].yy;
	
	ll sortx  = count_permutations(a, [&](pll p) { return p.xx; });
	ll sorty  = count_permutations(a, [&](pll p) { return p.yy; });

	ll sortxy = count_permutations(a, [&](pll p) { return p; });
	sort(all(a));
	FOR(i,1,n) if (a[i-1].yy > a[i].yy) sortxy = 0;

//	cout << sortx << " " << sorty << " " << sortxy << endl;
	
	ll res = factorial(n) - sortx - sorty + sortxy;
	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << endl;
}