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

	ll n; cin >> n;
	vector<set<ll>> s(n+10);
	FOR(i,0,n) {
		ll a; cin >> a;
		s[a].insert(i+1);
	}


	vi res(n);
	bool ok = true;
	ll cur = 0;

	FOR(i,0,n) {
		while (cur >= 0 && !sz(s[cur])) cur -= 3;
		if (cur < 0) {
			ok = false;
			break;
		}
		res[i] = *begin(s[cur]);
		s[cur].erase(begin(s[cur]));
		cur++;
	}

	if (ok) {
		cout << "Possible" << endl;
		FOR(i,0,n-1) cout << res[i] << " ";
		cout << res[n-1] << endl;
	} else {
		cout << "Impossible" << endl;
	}
}