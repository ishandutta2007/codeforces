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

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

int n, m;
int fib[1000100];
const int MOD = 1000000000;
int a[210000];
int main() {
	cin >> n >> m;
	fib[0] = 1;
	fib[1] = 1;
	FOR(i, 2, 1000000) fib[i] = (fib[i-2]+fib[i-1]) % MOD;
	REP(i, n) scanf("%d", &a[i]);
	
	
	REP(mm, m) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			a[x] = y;
		} else if (t == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			l--; r--;
			LL sum = 0;
			FOR(i, l, r + 1) sum = (sum + (LL)fib[i - l] * a[i]) % MOD;
			printf("%d\n", (int)sum);
		} else {
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
		}
	}
	return 0;
}