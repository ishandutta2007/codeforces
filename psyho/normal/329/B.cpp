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
#include <queue>
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

char mp[1010][1010];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int vs[1010][1010];
int main() {
	int r, c;
	cin >> r >> c;
	REP(i, r) scanf("%s", mp[i]);
	int ex, ey, sx, sy;
	REP(i, r) REP(j, c) {
		if (mp[i][j] == 'E') ex = i, ey = j;
	}
	
	queue < int > q;
	q.push(ex); q.push(ey); q.push(0);
	memset(vs, 0x3F, sizeof(vs));
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		int z = q.front(); q.pop();
		if (vs[x][y] <= z) continue;
		vs[x][y] = z;
		REP(d, 4) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c || mp[nx][ny] == 'T') continue;
			q.push(nx), q.push(ny), q.push(z + 1);
		}
	}
	
	int rv = 0;
	int ad = 0;
	REP(i, r) REP(j, c) {
		if (mp[i][j] == 'S') ad = vs[i][j];
	}
	
	REP(i, r) REP(j, c) if (isdigit(mp[i][j]) && vs[i][j] <= ad) rv += mp[i][j] - '0';
	cout << rv << endl;
	
	return 0;
}