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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll bestfit(ll n, ll w, ll x) {
	ll lo = w/2, hi = n - w/2;
	if (w % 2) {
		if (x > lo) return min(n-w,x-lo-1);
		return max(0ll,x-lo);
	} else {
		if (x >= lo && x <= hi) return x - w/2;
		if (x < lo) return 0;
		return n - w;
	}
}

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }

int main() {
	ios_base::sync_with_stdio(false);

	ll n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	
	ll g = gcd(a,b);
	a /= g, b /= g;
	ll f = min(n/a,m/b);
	ll w = f*a, h = f*b;

	ll x1 = bestfit(n,w,x);
	ll y1 = bestfit(m,h,y);
	
	cout << x1 << " " << y1 << " "  << x1 + w << " " << y1 + h << endl;

}