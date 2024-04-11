#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);

	ll n, m; cin >> n >> m;
	
	vi p(n);
	FOR(i,0,n) p[i] = i+1;
	
	ll best = -1;
	vector<vi> res;

	do {
		ll score = 0;
		FOR(i,0,n) FOR(j,i,n) {
			ll minv = 100;
			FOR(k,i,j+1) minv = min(minv,p[k]);
			score += minv;
		}
		cerr << score << endl;
		if (score > best) {
			res.clear();
			best = score;
			res.pb(p);
		} else if (score == best) {
			res.pb(p);
		}
	} while (next_permutation(all(p)));

	cerr << sz(res) << endl;

	FOR(i,0,n-1) cout << res[m-1][i] << " ";
	cout << res[m-1][n-1] << endl;

	


}