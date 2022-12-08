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

int n, m;
set<int> cn[100100];
int order[100100];

PII rv[100100];
int cm = 0;

inline int conn(int a, int b) {
	return cn[a].count(b) > 0;
}

inline void add(int a, int b) {
	rv[cm].X = a;
	rv[cm].Y = b;
	cm++;
}

int main() {
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		cn[a].insert(b);
		cn[b].insert(a);
	}
	
	if (n <= 6) {
		cm = 0;
		REP(i, n) REP(j, i) add(i, j);
		REP(i, 1 << cm) {
			int no = 0;
			bool ok = true;
			REP(j, cm) if (i & (1 << j)) no++;
			if (no != m) ok = false;
			int xm = 0;
			int en[10];
			ZERO(en);
			REP(j, n) REP(k, j) {
				if (i & (1 << xm)) {
					en[j]++;
					en[k]++;
					if (conn(j, k)) ok = false;
				}
				xm++;
			}
			REP(j, n) ok &= en[j] <= 2;
			if (!ok) continue;
			xm = 0;
			REP(j, n) REP(k, j) {
				if (i & (1 << xm)) {
					cout << (j+1) << ' ' << (k+1) << endl;
				}
				xm++;
			}
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	
	
	REP(i, n) order[i] = i;
	while (true) {
		random_shuffle(order, order + n);
		cm = 0;
		if (conn(order[0], order[n-1])) continue;
		add(order[0], order[n-1]);
		while (cm < m) {
			while (conn(order[cm-1], order[cm])) {
				if (cm >= m - 3) goto again;
				swap(order[cm], order[cm + rand() % (m - cm - 1)]);
			}
			add(order[cm-1], order[cm]);
		}
		REP(i, m) printf("%d %d\n", rv[i].X+1, rv[i].Y+1);
		return 0;
		again: ;
	}
	return 0;
}