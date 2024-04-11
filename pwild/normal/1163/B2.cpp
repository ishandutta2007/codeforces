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

bool check(map<ll,ll> &freq) {
	if (sz(freq) > 2) return false;
	if (sz(freq) == 1) {
		return begin(freq)->xx == 1 || begin(freq)->yy == 1;
	}
	
	pll p = *begin(freq);
	pll q = *next(begin(freq));

	if (p == mp(1LL,1LL)) return true;
	if (p.xx+1 == q.xx && q.yy == 1) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	
	ll m = 1e5 + 10;
	vl cnt(m);
	map<ll,ll> freq;

	ll res = 1;
	FOR(i,0,n) {
		ll x; cin >> x;
		if (cnt[x]) freq[cnt[x]]--;
		if (freq[cnt[x]] == 0) freq.erase(cnt[x]);
		cnt[x]++;
		freq[cnt[x]]++;
		
		if (check(freq)) res = i+1;
	}
	cout << res << endl;
}