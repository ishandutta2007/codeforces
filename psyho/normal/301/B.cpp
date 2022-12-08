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

int x[101];
int y[101];
int a[101];
int z[101];
int main() {
	int n, d;
	cin >> n >> d;
	a[0] = a[n-1] = 0;
	REP(i,n-2) cin >> a[i+1];
	REP(i,n) cin >> x[i] >> y[i];
	priority_queue<PII, VC < PII >, greater < PII > > pq;
	pq.push(MP(0, 0));
	REP(i, n) z[i] = 1 << 30;
	while (!pq.empty()) {
		PII p = pq.top(); pq.pop();
		if (z[p.Y] <= p.X) continue;
		if (p.Y == n-1) {
			printf("%d\n",p.X);
			return 0;
		}
		z[p.Y] = p.X;
		REP(i, n) if (i!=p.Y) pq.push(MP(p.X+d*abs(x[i]-x[p.Y])+d*abs(y[i]-y[p.Y])-a[p.Y],i));
	}
	return 0;
}