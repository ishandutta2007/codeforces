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

VS vs;
VI a;
#define MAXN 1234567
int d[MAXN][22];
int main() {
	ios_base::sync_with_stdio(0);
	int n, r, c;
	cin >> n >> r >> c;
	vs = VS(n);
	REP(i, n) cin >> vs[i];
	a = VI(n);
	REP(i, n) a[i] = vs[i].S;
	int sz = -1;
	int pos = 0;
	REP(i, 22) d[n][i] = n;
	REP(i, n) {
		while (pos < n && sz + 1 + a[pos] <= c) {
			sz += a[pos] + 1;
			pos++;
		}
		d[i][0] = pos;
		sz -= a[i] + 1;
	}
	FOR(j, 1, 21) REP(i, n) d[i][j] = d[d[i][j-1]][j-1];
	
	int bv = 0;
	int bp = 0;
	REP(i, n) {
		int ap = i;
		REP(j, 21) if (r & (1 << j)) ap = d[ap][j];
		if (ap - i > bv) {
			bp = i;
			bv = ap - i;
		}
	}
	
	int cursz = -1;
	FOR(i, bp, bp + bv) {
		if (cursz + 1 + vs[i].S > c) {
			cout << endl;
			cursz = -1;
		}
		if (cursz != -1) cout << ' ';
		cout << vs[i];
		cursz += 1 + vs[i].S;
	}
	
	return 0;
}