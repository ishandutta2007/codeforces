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
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int gcd(int a, int b) { return (b == 0) ? a : gcd(b,a%b); }

int main() {
	ios_base::sync_with_stdio(false);

	int n, x0, y0; cin >> n >> x0 >> y0;

	set<pii> s;
	vi x(n), y(n);
	FOR(i,0,n) {
		cin >> x[i] >> y[i];
		x[i] -= x0;
		y[i] -= y0;
		if (mp(x[i],y[i]) < mp(0,0)) x[i] = -x[i], y[i] = -y[i];
	 	int g = gcd(abs(x[i]),abs(y[i]));
		s.emplace(x[i]/g,y[i]/g);
	}

	cout << sz(s) << endl;


}