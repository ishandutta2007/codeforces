#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
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

	string n; cin >> n;
	ll k = sz(n);
	vector<string> res(10,string(k,'0'));
	FOR(i,0,k) {
		ll d = n[i]-'0';
		FOR(j,0,d) res[j][i] = '1';
	}

	vector<string> res2;
	FOR(j,0,10) {
		if (res[j] == string(k,'0')) break;
		FOR(i,0,k) if (res[j][i] == '1') {
			res2.pb(res[j].substr(i));
			break;
		}
	}
	cout << sz(res2) << endl;
	FOR(i,0,sz(res2)-1) cout << res2[i] << " ";
	cout << res2[sz(res2)-1] << endl;




}