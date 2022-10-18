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

// s >= 2n -> yes, (s-n+1) 1 1 ... 1, n
// s < 2n -> no? there is at least one 1
//
// 2 2 2 2 2 1 2 2 2 2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, s;
	cin >> n >> s;

	if (2*n <= s) {
		cout << "YES" << endl;
		cout << s-n+1;
		FOR(i,1,n) cout << " 1";
		cout << endl;
		cout << n << endl;
	} else {
		cout << "NO" << endl;
	}
}