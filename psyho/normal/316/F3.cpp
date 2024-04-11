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

int h, w;
int data[1700][1700];
int edge[1700][1700];

int dr[] = {-1,1,0,0,-1,-1,1,1};
int dc[] = {0,0,-1,1,-1,1,-1,1};

int main() {
	cin >> h >> w;
	REP(i, h) REP(j, w) scanf("%d", &data[i][j]);
	
	REP(r, h) REP(c, w) if (data[r][c]) {
		REP(d, 4) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= h || nc < 0 || nc >= w || data[nr][nc] == 0) edge[r][c] = 1;
		}
	}
	
	VI rays;
	
	#define PX pair <int, int>
	REP(r, h) REP(c, w) if (edge[r][c]) {
		VC < PX > v;
		int cr = r;
		int cc = c;
		while (edge[cr][cc]) {
			v.PB(MP(cr, cc));
			edge[cr][cc] = 0;
			REP(d, 8) {
				int nr = cr + dr[d];
				int nc = cc + dc[d];
				if (nr >= 0 && nr < h && nc >= 0 && nc < w && edge[nr][nc]) {
					cr = nr;
					cc = nc;
					break;
				}
			}
		}
		
		int bv = -1;
		int bp = -1;
		REP(i, v.S) FOR(j, 15, 110) {
			int sx = v[i].X;
			int sy = v[i].Y;
			int ex = v[(i+j)%v.S].X;
			int ey = v[(i+j)%v.S].Y;
			if (abs(sx-ex) > 35 || abs(sy-ey) > 35) break;
			if (abs(sx-ex) <= 5 && abs(sy-ey) <= 5 && abs(sx-ex)+abs(sy-ey) <= 7) {
				if (j > bv) {
					bv = j;
					bp = i;
				}
				
			}
		}
		
		int count = 0;
		REP(i, v.S) FOR(j, 15, 110) {
			int sx = v[(i+bp)%v.S].X;
			int sy = v[(i+bp)%v.S].Y;
			int ex = v[(i+j+bp)%v.S].X;
			int ey = v[(i+j+bp)%v.S].Y;
			if (i+j>v.S) break;
			if (abs(sx-ex) > 35 || abs(sy-ey) > 35) break;
			if (abs(sx-ex) <= 5 && abs(sy-ey) <= 5 && abs(sx-ex)+abs(sy-ey) <= 7) {
				count++;
				i += j + 1;
				break;
			}
		}
		
		if (count) rays.PB(count);
	}
	
	sort(ALL(rays));
	cout << rays.S << endl;
	REP(i, rays.S) cout << rays[i] << ' ';
	cout << endl;
	
	return 0;
}