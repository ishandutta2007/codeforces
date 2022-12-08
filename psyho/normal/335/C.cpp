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

int x[100][2];
int gn[110][4];

int go(int no, int t) {
	int &rv = gn[no][t];
	if (rv != -1) return rv;
	if (no == 0) return rv = 0;
	
	int us[500];
	ZERO(us);
	if (t == 0) {
		REP(i, no) us[go(i, 1) ^ go(no - 1 - i, 1)] = 1;
	} else if (t == 1) {
		REP(i, no) us[go(i, 1) ^ go(no - 1 - i, 2)] = 1;
		REP(i, no - 1) us[go(i, 1) ^ go(no - 1 - i, 3)] = 1;
	} else if (t == 2) {
		REP(i, no) us[go(i, 2) ^ go(no - 1 - i, 2)] = 1;
		FOR(i, 1, no - 1) us[go(i, 3) ^ go(no - 1 - i, 3)] = 1;
	} else if (t == 3) {
		REP(i, no - 1) us[go(i, 2) ^ go(no - 1 - i, 3)] = 1;
	}
	
	rv = 0;
	while (us[rv]) rv++;
	return rv;
}

int main() {
	int r, n;
	cin >> r >> n;
	memset(gn, -1, sizeof(gn));
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		x[a][b] = 1;
	}
	
	int t = -1;
	int no = 0;
	int rv = 0;
	REP(i, r + 1) {
		if (i == r || x[i][0] || x[i][1]) {
			int nt = i == r ? -1 : x[i][0] ? 0 : 1;
			int z = -1;
			if (t == -1 && nt == -1) {
				z = 0;
			} else if (t == -1 || nt == -1) {
				z = 1;
			} else if (t == nt) {
				z = 2;
			} else if (t != nt) {
				z = 3;
			}
			rv ^= go(no, z);
			t = nt;
			no = 0;
		} else {
			no++;
		}
	}
	cout << (rv == 0 ? "LOSE" : "WIN") << endl;
}