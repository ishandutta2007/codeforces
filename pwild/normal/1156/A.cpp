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

ll go() {
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll res = 0;
	FOR(i,0,n-1) {
		if (a[i] == 1 && a[i+1] == 2) res += 3;
		if (a[i] == 1 && a[i+1] == 3) res += 4;
		if (a[i] == 2 && a[i+1] == 1) res += 3;
		if (a[i] == 2 && a[i+1] == 3) return oo;
		if (a[i] == 3 && a[i+1] == 1) res += 4;
		if (a[i] == 3 && a[i+1] == 2) return oo;
	}
	FOR(i,0,n-2) {
		if (a[i] == 3 && a[i+1] == 1 && a[i+2] == 2) res--;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll res = go();
	if (res == oo) cout << "Infinite" << endl;
	else {
		cout << "Finite" << endl;
		cout << res << endl;
	}

}