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

char mp[110][110];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n;
int total;
void sim(int x, int y) {
	x--;
	y--;
	int no = 0;
	int empty = 0;
	
	while (true) {
		if (mp[x][y] == '.') break;
		int t = -1;
		char c = mp[x][y];
		if (mp[x][y] == '>') t = 3;
		if (mp[x][y] == '<') t = 2;
		if (mp[x][y] == '^') t = 0;
		if (mp[x][y] == 'v') t = 1;
		
		int moves = 0;
		while (true) {
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) goto done;
			if (mp[nx][ny] == '.') {
				mp[x][y] = '.';
				x += dx[t];
				y += dy[t];
				mp[x][y] = c;
				moves++;
				empty = 0;
			} else {
				no += moves > 0;
				x += dx[t];
				y += dy[t];
				break;
			}
		}
		empty++;
		if (empty > 200) break;
		continue;
		
		done:
		break;
	}
	
	DB(x);
	DB(y);
	DB(no);
	REP(i, n) printf("%s\n", mp[i]);
	
}

int main() {
	cin >> n >> total;
	
	if (n == 5) {
		printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	} else if (n == 3) {
		printf(">vv\n^<.\n^.<\n1 3\n");
	} else {
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.v\n");
		printf("^v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		REP(i, 48) {
			printf("^>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.v\n");
			printf("^v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		}
		printf("^>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.v\n");
		printf("^.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		cout << 1 << ' ' << 1 << endl;
	}
	
	return 0;
}