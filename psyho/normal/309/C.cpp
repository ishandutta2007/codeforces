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

VI b;

int ono[30];
int no[30];

int ok(int x) {
	REP(i, 30) no[i] = ono[i];
	for (int i = x - 1; i >= 0; i--) {
		bool oo = false;
		FOR(j, b[i], 30) if (no[j]) {
			no[j]--;
			FOR(k, b[i], j) no[k]++;
			oo = true;
			break;
		}
		if (!oo) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REP(i, n) {
		int a;
		cin >> a;
		REP(j, 30) if (a & (1 << j)) ono[j]++;
	}
	b = VI(m);
	REP(i, m) cin >> b[i];
	sort(ALL(b));
	int l = 0, r = m;
	while (l < r) {
		int s = (l + r + 1) / 2;
		if (ok(s)) l = s; else r = s - 1;
	}
	cout << l << endl;
	return 0;
}