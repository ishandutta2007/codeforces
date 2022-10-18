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
typedef pair<int,int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
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

ll a[210];

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n, k; cin >> n >> k;
	FOR(i,0,n) cin >> a[i];
	ll best = -oo;
	FOR(l,0,n) FOR(r,l,n) {
		vi in,out;
		ll sum = 0;
		FOR(i,0,l) out.pb(a[i]);
		FOR(i,l,r+1) in.pb(a[i]), sum += a[i];
		FOR(i,r+1,n) out.pb(a[i]);
		sort(all(in));
		sort(out.rbegin(),out.rend());
		FOR(i,0,min(k,min(sz(in),sz(out)))) if (out[i] > in[i]) sum += out[i]-in[i]; else break;
		best = max(best,sum);
	}

	cout << best << endl;

}