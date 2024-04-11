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

LL A[1<<20];
int B[1<<20];
LL V[1<<20];
int OL[1<<20];
int OR[1<<20];
int OD[1<<20];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	REP(i, n) cin >> V[i];
	REP(i, m) cin >> OL[i] >> OR[i] >> OD[i];
	REP(i, m) OL[i]--;
	REP(i, m) OR[i]--;
	REP(i, k) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		B[x] += 1;
		B[y+1] -= 1;
	}
	
	LL op = 0;
	REP(i, m) {
		op += B[i];
		A[OL[i]] += op * OD[i];
		A[OR[i] + 1] -= op * OD[i];
	}
	
	LL v = 0;
	REP(i, n) {
		v += A[i];
		V[i] += v;
	}
	
	REP(i, n) {
		if (i) cout << ' ';
		cout << V[i];
	}
	
	cout << endl;
	
	

	return 0;
}