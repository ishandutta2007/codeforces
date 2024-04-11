#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;

struct Point {
	int x, y;

	void read() {
		scanf("%d%d", &x, &y);
	}

	int type() const {
		if  (x >= 0 && y >= 0) {
			return 0;
		}
		if  (x <= 0 && y >= 0) {
			return 1;
		} 
		if  (x <= 0 && y <= 0) {
			return 2;
		}
		return 3;
	}

	int operator % (const Point& b) const {
		return x * b.y - y * b.x;
	}

	int operator * (const Point& b) const {
		return x * b.x + y * b.y;
	}

	bool operator < (const Point& b) const {
		if  (type() != b.type()) {
			return type() < b.type();
		}
		return ((*this) % b) > 0;
	}
};

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
  
  	int n;
  	scanf("%d", &n);
  	vector<pair<Point, int>> ps(n);
  	forn(i, n) {
  		ps[i].fst.read();
  		ps[i].snd = i;
  	}

  	sort(all(ps));

  	ld mn = 10;
  	int id1 = -1, id2 = -1;
  	forn(i, n) {
  		auto a = ps[i].fst;
  		auto b = ps[(i + 1) % n].fst;
  		ld cur = fabs(atan2(a % b, a * b));
  		if  (cur < mn) {
  			mn = cur;
  			id1 = ps[i].snd;
  			id2 = ps[(i + 1) % n].snd;
  		}
  	}

  	printf("%d %d\n", id1 + 1, id2 + 1);

	return 0;
}