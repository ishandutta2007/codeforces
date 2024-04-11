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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<string,ll> val;
	val["[]"] = 0;
	val["()"] = 1;
	val["8<"] = 2;
	
	vvl winner = {
		{0,1,-1},
		{-1,0,1},
		{1,-1,0}
	};

	string s, t;
	cin >> s >> t;
	ll res = 0;
	FOR(i,0,sz(s)/2) {
		ll k1 = val[s.substr(2*i,2)];
		ll k2 = val[t.substr(2*i,2)];
		res += winner[k1][k2];
	}
	if (res  > 0) cout << "TEAM 1 WINS" << endl;
	if (res == 0) cout << "TIE" << endl;
	if (res  < 0) cout << "TEAM 2 WINS" << endl;

}