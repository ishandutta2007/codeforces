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

ll n, t;
string s;

string go() {
	cin >> n >> t >> s;
	
	s = "0" + s;

	ll i = 0;
	while (s[i] != '.') i++;

	s = s.substr(0,i) + s.substr(i+1);

	ll j = i;
	while (j < n && s[j] < '5') j++;
	
	if (j < n) {
		while (t > 0 && j > i && s[j] >= '5') {
			n = j, s[j-1]++, j--, t--;
		}
		if (t > 0 && j == i && s[j] >= '5') {
			n = j, t--;
			while (s[j-1] == '9') s[j-1] = '0', j--;
			s[j-1]++;
		}
	}
	
	s = s.substr(0,n);
	if (i < n) s = s.substr(0,i) + "." + s.substr(i);
	if (s[0] == '0') s = s.substr(1);
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << go() << endl;

}