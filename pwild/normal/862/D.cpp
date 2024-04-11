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

ll n;
bool s[1010];

ll ask() {
	cout << "? ";
	FOR(i,0,n) cout << s[i];
	cout << endl;
	ll res; cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	ll d0 = ask();
	s[0] = 1;
	ll d1 = ask();
	s[0] = 0;

	ll pos0 = -1, pos1 = -1;

	if (d0 > d1) {
		pos1 = 0;
		ll a = 0, b = n;
		// inv: ex. 0 in [a,b[
		while (b-a > 1) {
			memset(s,0,sizeof s);
			ll c = (a+b)/2;
			FOR(i,a,c) s[i] = 1;
			d1 = ask();
			ll sum = (c-a-d1+d0);
			assert(sum % 2 == 0);
			ll din0 = sum/2, din1 = c-a-din0;
			if (din1 > 0) b = c; else a = c;
		}
		pos0 = a;
	} else {
		pos0 = 0;
		ll a = 0, b = n;
		// inv: ex. 1 in [a,b[
		while (b-a > 1) {
			memset(s,0,sizeof s);
			ll c = (a+b)/2;
			FOR(i,a,c) s[i] = 1;
			d1 = ask();
			ll sum = (c-a-d1+d0);
			assert(sum % 2 == 0);
			ll din0 = sum/2, din1 = c-a-din0;
			if (din0 > 0) b = c; else a = c;
		}
		pos1 = a;
	}
	cout << "! " << pos0+1 << " " << pos1+1 << endl;
}