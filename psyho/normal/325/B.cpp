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

#define FORE(it,c)  for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
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

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

#define LX LL

LX calc(LX i, LX s, LX n) {
	LX v = s * (s - 1) / 2;
	LX z = s;
	REP(j, i) {
		v += z;
		z *= 2;
		if (v > n) break;
	}
	return v;
}

int main() {
	LL n;
	cin >> n;
	
	VC < LL > rv;
	
	REP(i, 64) {
		LX l = 0;
		LX r = 1LL << 30;
		
		while (l < r) {
			LX s = (l + r) / 2;
			LX v = calc(i, 2 * s + 1, n);
			
			if (v < n) {
				l = s + 1;
			} else {
				r = s;
			}
		}
		
		if (n == calc(i, 2 * l + 1, n)) rv.PB((LL)(2 * l + 1) * (1LL << i));
	}
	
	sort(ALL(rv));
	if (rv.S == 0) cout << -1 << endl;
	REP(i, rv.S) cout << rv[i] << endl;
	return 0;
}