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

bool solve() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));
	
	map<ll,ll> freq;
	FOR(i,0,n) freq[a[i]]++;

	ll cnt2 = 0, has2 = -1;
	for (auto pr: freq) {
		if (pr.yy > 2) return false;
		if (pr.yy == 2) has2 = pr.xx, cnt2++;
	}
	
	if (cnt2 > 1) return false;
	if (cnt2 == 1) {
		if (has2 == 0) return false;
		if (freq.count(has2-1)) return false;
	}
	
	ll moves = 0;
	FOR(i,0,n) moves += a[i]-i;
	
	return moves%2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << (solve() ? "sjfnb" : "cslnb") << endl;
}