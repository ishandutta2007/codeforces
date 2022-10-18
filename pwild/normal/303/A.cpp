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

ll a[20], b[20], c[20];

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;
	if (n % 2) {
		FOR(i,0,n) {
			if (i) cout << " ";
			cout << i;
		}
		cout << endl;
		FOR(i,0,n) {
			if (i) cout << " ";
			cout << i;
		}
		cout << endl;
		FOR(i,0,n) {
			if (i) cout << " ";
			cout << (2*i) % n;
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}

/*
	FOR(n,2,20) {
		FOR(i,0,n) a[i] = b[i] = i;

		do {
			ll h = 0;
			FOR(i,0,n) {
				c[i] = a[i] + b[i];
				c[i] %= n;
				h |= (1 << c[i]);
			}
			if (h == (1 << n) - 1) {
				FOR(i,0,n) cout << a[i] << " ";
				cout << endl;
				FOR(i,0,n) cout << b[i] << " ";
				cout << endl;
				FOR(i,0,n) cout << c[i] << " ";
				cout << endl;
				break;
			}
		} while (next_permutation(b,b+n));

	}
*/

}