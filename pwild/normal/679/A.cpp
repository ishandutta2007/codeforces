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

int main() {
	
	ll p = -1;
	for (ll q: {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}) {
		cout << q << endl;
		string ans;
		cin >> ans;
		if (ans == "yes") {
			if (p != -1) {
				cout << "composite" << endl;
				return 0;
			}
			p = q;
		}
	}
	if (p == -1) {
		cout << "prime" << endl;
		return 0;
	}
	if (p < 10) {
		cout << p*p << endl;
		string ans;
		cin >> ans;
		if (ans == "yes") {
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
}