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

int d[500][500];
int x[500][500];
int n;
int order[500];
int ok[500];
int main() {
	cin >> n;
	REP(i, n) REP(j, n) cin >> d[i][j];
	REP(i, n) cin >> order[i];
	
	REP(i, n) REP(j, n) if (i != j) x[i][j] = (1 << 29);
	VC < LL > rv(n);
	for (int o = n - 1; o >= 0; o--) {
		int v = order[o] - 1;
		ok[v] = 1;
		REP(i, n) if (ok[i]) REP(j, n) if (ok[j])
			x[v][i] = min(x[v][i], d[v][j] + x[j][i]);
		REP(i, n) if (ok[i]) REP(j, n) if (ok[j])
			x[i][v] = min(x[i][v], x[i][j] + d[j][v]);
		REP(i, n) if (ok[i]) REP(j, n) if (ok[j]) {
			x[i][j] = min(x[i][j], x[i][v] + x[v][j]);
			rv[o] += x[i][j];
		}
	}
	
	REP(i, rv.S) {
		if (i) cout << ' ';
		cout << rv[i];
	}
	cout << endl;
}