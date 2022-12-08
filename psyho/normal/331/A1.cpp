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

int x[1001000];
map < LL, pair < LL, LL > > ff;
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &x[i]);
	
	LL sum = 0;
	LL rv = -(1LL << 60);
	LL ba, bb;
	REP(i, n) {
		sum += max(0, x[i]);
		if (ff.count(x[i]) == 0) {
			ff[x[i]] = MP(sum - max(0, x[i]), i);
		} else {
			LL av = sum - ff[x[i]].X;
			if (x[i] < 0) av += 2 * x[i];
			if (av > rv) {
				rv = av;
				ba = ff[x[i]].Y;
				bb = i;
			}
		}
	}
	VI p;
	REP(i, n) if (i < ba || i > bb || i != ba && i != bb && x[i] < 0) p.PB(i);
	cout << rv << ' ' << p.S << endl;
	REP(i, p.S) printf("%d ", p[i] + 1);
	cout << endl;
}