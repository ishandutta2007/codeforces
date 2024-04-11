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
	ll n = sz(a);

	map<ll,ll> cnt;
	ll base = 0;
	cnt[a[0]]++, cnt[a[n-1]]++;
	FOR(i,0,n-1) if (a[i] == a[i+1]) cnt[a[i]] += 2, base++;

	// cnt[x]-2 <= sum_{y != x} cnt[y]
	// 2*cnt[x]-2 <= 2*base+2
	// cnt[x] <= base+2

	ll x = a[0];
	for (auto [y,c]: cnt) if (c > cnt[x]) x = y;

	ll most = base;
	if (cnt[x]-2 <= base) return base;

	FOR(i,0,n-1) if (a[i] != a[i+1] && a[i] != x && a[i+1] != x) {
		most++;
	}

	if (cnt[x]-2 <= most) return cnt[x]-2;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];
		cout << solve(a) << endl;
	}
}