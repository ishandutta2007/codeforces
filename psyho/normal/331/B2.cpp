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

int m[1001000];
int v[1001000];
int n;
int s[1 << 21];

void add(int p, int x) {
	p += 1 << 20;
	while (p) {
		s[p] += x;
		p >>= 1;
	}
}

int sum(int p) {
	if (p < 0) return 0;
	p += 1 << 20;
	int rv = 0;
	while (p) {
		if (p&1) {
			p >>= 1;
		} else {
			rv += s[p];
			p = (p - 1) >> 1;
		}
	}
	return rv;
}

int main() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &m[i]);
	REP(i, n) v[--m[i]] = i;
	REP(i, n - 1) if (v[i] > v[i+1]) add(i, 1);
	int q;
	cin >> q;
	REP(i, q) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		b--;
		c--;
		if (a == 1) {
			printf("%d\n", sum(c-1) - sum(b-1) + 1);
		} else {
			int nb = m[b];
			int nc = m[c];
			swap(m[b], m[c]);
			b = nb;
			c = nc;
			if (b > c) swap(b, c);
			if (b && v[b] < v[b-1]) add(b - 1, -1);
			if (v[b+1] < v[b]) add(b, -1);
			if (b + 1 != c && v[c] < v[c-1]) add(c - 1, -1);
			if (c < n - 1 && v[c+1] < v[c]) add(c, -1);
			swap(v[b], v[c]);
			if (b && v[b] < v[b-1]) add(b - 1, +1);
			if (v[b+1] < v[b]) add(b, +1);
			if (b + 1 != c && v[c] < v[c-1]) add(c - 1, +1);
			if (c < n - 1 && v[c+1] < v[c]) add(c, +1);
		}
	}
	return 0;
}