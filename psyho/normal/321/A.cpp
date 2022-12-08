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
#define PII        pair <LL, LL>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

string s;
LL x, y;
bool ok = false;


PII sim(string r, int no = 1) {
	LL cx = 0, cy = 0;
	REP(i, r.S) {
		if (x == cx && y == cy) ok = true;
		if (r[i] == 'U') cy++;
		if (r[i] == 'D') cy--;
		if (r[i] == 'L') cx--;
		if (r[i] == 'R') cx++;
	}
	cx *= no;
	cy *= no;
	return MP(cx, cy);
}

int main() {
	cin >> x >> y;
	cin >> s;
	PII p = sim(s);
	LL ld = abs(x) + abs(y);
	while (true) {
		if (p.X == 0 && p.Y == 0) break;
		LL d = abs(x) + abs(y);
		if (d > 1000 && d > ld) break;
		ld = d;
		
		LL no = 1;
		LL xd = d;
		while (xd > 10000) {
			no *= 2;
			xd /= 2;
		}
		
		x -= p.X * no;
		y -= p.Y * no;
		sim(s);
	}
	cout << (ok ? "Yes" : "No") << endl;
}