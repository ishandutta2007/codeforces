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

const LL MOD = 1000000000039LL;
const LL MUL = 51;
LL hash(string &s, int l, int r) {
	LL h = 0;
	FOR(i, l, r + 1) h = (h * MUL + s[i] + 1 - 'a') % MOD;
	return h;
}

string s;
string p[10];
int l[10];
int r[10];
map<LL, int> occ[10];
int main() {
	cin >> s;
	int n;
	cin >> n;
	REP(i, n) cin >> p[i] >> l[i] >> r[i];
	
	REP(i, n) REP(j, p[i].S) FOR(k, j, p[i].S) occ[i][hash(p[i], j, k)]++;
	
	int rv = 0;
	set < LL > vs;
	REP(i, s.S) FOR(j, i, s.S) {
		bool ok = true;
		LL h = hash(s, i, j);
		if (vs.count(h)) continue;
		vs.insert(h);
		REP(k, n) {
			int v = occ[k][h];
			if (v < l[k] || v > r[k]) ok = false;
		}
		if (ok) rv++;
	}	
	
	cout << rv << endl;
	
	return 0;
}