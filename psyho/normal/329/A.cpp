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

char x[110][110];
VC < PII > rv;
int main() {
	int n;
	cin >> n;
	REP(i, n) scanf("%s", x[i]);
	REP(step, 2) {
		rv.clear();
		REP(i, n) {
			int f = -1;
			REP(j, n) if (x[i][j] == '.') f = j;
			if (f == -1) goto again;
			rv.PB(MP(i, f));
		}
		
		if (step == 0) REP(i, n) cout << (rv[i].X + 1) << ' ' << (rv[i].Y + 1) << endl;
		if (step == 1) REP(i, n) cout << (rv[i].Y + 1) << ' ' << (rv[i].X + 1) << endl;
		return 0;
		again: ;
		REP(i, n) REP(j, i) swap(x[i][j], x[j][i]);
	}
	cout << -1 << endl;
	
	return 0;
}