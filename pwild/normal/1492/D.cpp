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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, k;
	cin >> a >> b >> k;

	if (k == 0) {
		cout << "Yes" << endl;
		cout << string(b,'1') << string(a,'0') << endl;
		cout << string(b,'1') << string(a,'0') << endl;
	} else if (a == 0 || b == 1) {
		cout << "No" << endl;
	} else if (k > a+b-2) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		string z;
		while (k < a+b-1) {
			if (b > 1) z.pb('1'), b--;
			else z.pb('0'), a--;
		}
		assert(k == a+b-1 && z[0] != '0' && b >= 1 && a >= 1);
		cout << z << "1" << string(a-1,'0') << string(b-1,'1') << "0" << endl;
		cout << z << string(a,'0') << string(b,'1') << endl;
//		cout << "11" << string(a-1,'0') << string(b-2,'1') << "0" << endl;
//		cout << "1" << string(a,'0') << string(b-1,'1') << endl;
	}
}