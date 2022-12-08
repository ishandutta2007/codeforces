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

int ar[3040][3040];
int eh[3040][3040];
int ev[3040][3040];
int x0[100000];
int y0[100000];
int x1[100000];
int y1[100000];
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
		FOR(y,y0[i],y1[i])FOR(x,x0[i],x1[i]) ar[y+1][x+1] = 1;
		FOR(y,y0[i],y1[i]) ev[x0[i]][y] = ev[x1[i]][y] = 1;
		FOR(x,x0[i],x1[i]) eh[y0[i]][x] = eh[y1[i]][x] = 1;
	}
	
	FOR(y, 0, 3010) FOR(x, 1, 3010) ar[y][x] += ar[y][x-1];
	FOR(y, 1, 3010) FOR(x, 0, 3010) ar[y][x] += ar[y-1][x];
	FOR(i, 0, 3010) FOR(j, 1, 3010) if (ev[i][j]) ev[i][j] += ev[i][j-1];
	FOR(i, 0, 3010) FOR(j, 1, 3010) if (eh[i][j]) eh[i][j] += eh[i][j-1];
	
	REP(i, n) {
		int l = 1, r = 3000 - max(x0[i], y0[i]);
		while (l < r) {
			int s = (l + r + 1) / 2;
			int sum = ar[y0[i]+s][x0[i]+s] - ar[y0[i]][x0[i]+s] - ar[y0[i]+s][x0[i]] + ar[y0[i]][x0[i]];
			if (sum < s * s) {
				r = s - 1;
			} else {
				l = s;
			}
		}
		if (l) while (ev[x0[i]][y0[i]+l-1] < l) l--;
		if (l) while (eh[y0[i]][x0[i]+l-1] < l) l--;
		int x = x0[i], y = y0[i];
		int steps = l;
		FOR(sz, 1, l + 1) {
			x++;
			y++;
			if (ev[x][y-1] >= sz && eh[y][x-1] >= sz) {
				VI v;
				REP(j, n) if (x0[j] >= x0[i] && y0[j] >= y0[i] && x1[j] <= x && y1[j] <= y) v.PB(j+1);
				printf("YES %d\n", v.S);
				REP(j, v.S) printf("%d ", v[j]);
				return 0;
			}
		}
	}
	
	puts("NO");
	return 0;
}