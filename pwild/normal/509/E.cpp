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
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const string V = "AEIOUY";
double a[500010], b[500010];

bool vowel(char c) {
	return V.find(c) != string::npos;
}

int main() {
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	ll n = sz(s);
	ll m = (n-1)/2;
	a[m] = (n % 2) ? 2.0/double(n+1) : 2.0/double(n) + 2.0/double(n+2);
	FORD(i,0,m) {
		a[i] = a[i+1] + 1.0/double(i+1) + 1.0/double(n-i);
	}
	b[0] = a[0];
	FOR(i,1,m+1) b[i] = a[i] + b[i-1];
	
//	FOR(i,0,(n-1)/2+1) cerr << a[i] << endl;

	double res = 0;
	FOR(i,0,n) if (vowel(s[i])) {
		res += b[min(i,n-i-1)];
	}
	cout << fixed << setprecision(12) << res << endl;
	
}