#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <emmintrin.h>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)    memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S          size()
#define LL          long long
#define ULL        unsigned long long
#define LD          long double
#define MP          make_pair
#define X          first
#define Y          second
#define VC          vector
#define PII        pair <int, int>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

int main() {
	int n, l, t;
	cin >> n >> l >> t;
	VI v(n*3);
	REP(i, n) {
		cin >> v[i];
		v[i+n] = v[i]-l;
		v[i+2*n] = v[i]+l;
	}
	sort(ALL(v));
	int tn = (2 * t) / l;
	int tl = (2 * t) % l;
	double rv = 0;
	REP(i, n) {
		int v0 = v[n+i]-tl;
		int v1 = v[n+i]+tl;
		int xp0 = lower_bound(ALL(v), v0) - v.begin();
		int xp1 = upper_bound(ALL(v), v1) - v.begin();
		// int p0 = n+i;
		// int p1 = n+i;
		// while (v[p0-1] >= v0) p0--;
		// while (v[p1+1] <= v1) p1++;
		// if (xp0 != p0 || xp1 != p1 + 1) {
			// cerr << i << ' ' << xp0 << ' ' << xp1 << ' ' << p0 << ' ' << (p1 + 1) << endl;
		// }
		// rv += (((n+i) - p0) + (p1 - (n+i) - 1));
		rv += (((n+i) - xp0) + (xp1 - (n+i) - 1));
	}
	printf("%.9f\n", rv / 8 + (double)n * (n - 1) * tn / 4.);
	return 0;
}