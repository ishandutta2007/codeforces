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

ll solve() {
	ll n, m;
	cin >> n >> m;

	ll K = 30, sum = 0;
	vl cnt(K+1);
	while (m--) {
		ll x; cin >> x;
		sum += x;
		FOR(k,0,K) if (x & (1 << k)) cnt[k]++;
	}
	
	if (sum < n) return -1;

	ll res = 0;
	FOR(i,0,K) {
		if (n & (1 << i)) {
			ll j = i;
			while (!cnt[j]) j++;
			res += j-i;
			cnt[j]--;
			FOR(k,i,j) cnt[k]++;
		}
		cnt[i+1] += cnt[i]/2;
		cnt[i] %= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) cout << solve() << endl;
}