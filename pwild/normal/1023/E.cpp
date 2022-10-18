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

ll n;

bool ask(ll a, ll b, ll c, ll d) {
	if (a < 1 || c < a || n < c) return false;
	if (b < 1 || d < b || n < d) return false;
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	string ans; cin >> ans;
	if (ans == "BAD") exit(0);
	return ans == "YES";
}

int main() {
	cin >> n;
	
	string fst, snd;
	for (ll x = 1, y = 1; x+y < n+1;) {
		if (ask(x+1,y,n,n)) {
			x++;
			fst += 'D';
		} else {
			y++;
			fst += 'R';
		}
	}
	for (ll x = n, y = n; x+y > n+1;) {
		if (ask(1,1,x,y-1)) {
			y--;
			snd += 'R';
		} else {
			x--;
			snd += 'D';
		}
	}
	reverse(all(snd));
	cout << "! " << fst << snd << endl;
}