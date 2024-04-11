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
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	ll n = sz(s);

	vector<string> a(3,string(n,'a'));
	
	FOR(i,0,n) {
		ll x = i;
		FOR(j,0,3) a[j][i] += x%26, x /= 26;
	}
	
	vector<string> b(3);
	FOR(j,0,3) {
		cout << "? " << a[j] << endl;
		cin >> b[j];
	}
	
	vl p(n);
	FOR(i,0,n) {
		ll y = 0;
		FORD(j,0,3) y = 26*y + b[j][i]-'a';
		p[y] = i;
	}
	
	string t(n,' ');
	FOR(i,0,n) t[i] = s[p[i]];
	
	cout << "! " << t << endl;
}