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
	int n;
	cin >> n;
	VI v(2*n-1);
	REP(i,v.S) cin >> v[i];
	int zero = 0;
	REP(i,v.S) zero |= v[i] == 0;
	int rv = -(1<<20);
	int m = 0;
	REP(i,v.S) m += v[i] < 0;
	REP(i,v.S) v[i] = abs(v[i]);
	sort(ALL(v));
	if (n%2||m%2==0) {
		rv = 0;
		REP(i,v.S) rv += v[i];
	} else {
		rv = -v[0];
		FOR(i,1,v.S) rv += v[i];
	}
	
	printf("%d\n",rv);
	return 0;
}