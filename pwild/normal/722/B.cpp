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

const set<char> vowels = {'a','e','i','o','u','y'};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl p(n);
	FOR(i,0,n) cin >> p[i];
	string foo;
	getline(cin,foo);
	FOR(i,0,n) {
		string line;
		getline(cin,line);
		ll cur = 0;
		for (char c: line) if (has(vowels,c)) cur++;
		if (cur != p[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
			/*
		getline(cin,line);
		stringstream ss(line);
		vector<string>*/

}