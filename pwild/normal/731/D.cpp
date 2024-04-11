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

ll go() {
	ll n, m; cin >> n >> m;
	vvl a(n);
	FOR(i,0,n) {
		ll len; cin >> len;
		a[i].resize(len);
		FOR(j,0,len) cin >> a[i][j], a[i][j]--;
	}
	set<ll> ok;
	FOR(i,0,m) ok.insert(i);
	FOR(i,0,n-1) {
		ll j = 0;
		while (j < sz(a[i]) && j < sz(a[i+1]) && a[i][j] == a[i+1][j]) j++;
		if (j == sz(a[i])) continue;
		if (j == sz(a[i+1])) return -1;
		ll x = (m-a[i][j]) % m, y = (m-a[i+1][j]) % m;
		auto it1 = ok.lower_bound(x), it2 = ok.lower_bound(y);
		if (x < y) {
			ok.erase(begin(ok),it1);
			it2 = ok.lower_bound(y);
			ok.erase(it2,end(ok));
		} else {
			ok.erase(it2,it1);
		}
	}
	return sz(ok) ? *begin(ok) : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << go() << endl;
}