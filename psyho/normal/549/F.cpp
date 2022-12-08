#include <bits/stdc++.h>
#include <sys/time.h>
//#include <emmintrin.h>

using namespace std;

#define INLINE   inline __attribute__ ((always_inline))
#define NOINLINE __attribute__ ((noinline))

#define ALIGNED __attribute__ ((aligned(16)))

#define likely(x)   __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

#define SSELOAD(a)     _mm_load_si128((__m128i*)&a)
#define SSESTORE(a, b) _mm_store_si128((__m128i*)&a, b)

#define byte        unsigned char
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define ULL         unsigned long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define PII         pair <int, int>
#define VB          VC < byte >
#define VVB         VC < VB >
#define VI          VC < int >
#define VVI         VC < VI >
#define VVVI        VC < VVI >
#define VPII        VC < PII >
#define VD          VC < double >
#define VVD         VC < VD >
#define VVVD        VC < VVD >
#define VF          VC < float >
#define VVF         VC < VF >
#define VVVF        VC < VVF >
#define VS          VC < string >
#define VVS         VC < VS >
#define DB(a)       cerr << #a << ": " << (a) << endl;

template<class A, class B> ostream& operator<<(ostream &os, pair<A,B> &p) {os << "(" << p.X << "," << p.Y << ")"; return os;}
template<class A, class B, class C> ostream& operator<<(ostream &os, tuple<A,B,C> &p) {os << "(" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << ")"; return os;}
template<class T> ostream& operator<<(ostream &os, VC<T> &v) {os << "{"; REP(i, v.S) {if (i) os << ", "; os << v[i];} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream &os, map<A,B> &v) {os << "{"; for (pair<A,B> p : v) {os << "(" << p.X << ":" << p.Y << "),";} os << "}"; return os;}
template<class T> ostream& operator<<(ostream &os, set<T> &s) {VS vs(ALL(s)); return os << vs;}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str();}
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

INLINE int rint() {
	int x; cin >> x; return x;
}

INLINE int rdouble() {
	double d; cin >> d; return d;
}

double getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec * 1e-6;
}

VI v;

int v1[310000];
int v2[310000];
int p1[2000000];
int p2[2000000];
int n, k;
LL go(int a, int b) {
	if (a>=b) return 0;
	
	int sum = 0;
	for (int i = a; i <= b; i++) v1[i] = v2[i] = 0;
	sum = 0;
	for (int i = a; i <= b; i++) {
		sum += v[i];
		sum %= k;
		v1[i] = sum;
		p1[sum]++;
	}
	sum = 0;
	for (int i = b; i >= a; i--) {
		sum += v[i];
		sum %= k;
		v2[i] = sum;
		p2[sum]++;
	}
	
	VPII vp;
	FOR(i,a,b+1) vp.PB(MP(-v[i],i));
	sort(ALL(vp));
	
	LL rv = 0;
	
	VPII calls;
	int ca = a, cb = b;
	REP(i, vp.S) {
		if (ca>=cb) break;
		if (vp[i].Y < ca || vp[i].Y > cb) continue;
		int m = vp[i].Y;
		if (m-ca<cb-m) {
			calls.PB(MP(ca, m-1));
			for (int j = ca; j <= m; j++) {
				p1[v1[j]]--;
				p2[v2[j]]--;
			}
			for (int j = m; j >= ca; j--) {
				rv += p1[(-(v2[j] - v2[m]) + v1[m] + 5 * k) % k];
				if (j != m) rv += (v2[j] - v2[m]) % k == 0;
			}
			ca = m+1;
		} else {
			calls.PB(MP(m+1, cb));
			for (int j = cb; j >= m; j--) {
				p1[v1[j]]--;
				p2[v2[j]]--;
			}
			for (int j = m; j <= cb; j++) {
				rv += p2[(-(v1[j] - v1[m]) + v2[m] + 5 * k) % k];
				if (j != m) rv += (v1[j] - v1[m]) % k == 0;
			}
			cb = m-1;
		}
		//rv += go(ca, cb);
		//break;
	}
	for (int j = ca; j <= cb; j++) {
		p1[v1[j]]--;
		p2[v2[j]]--;
	}
	
	for (PII &p : calls) rv += go(p.X, p.Y);
	//cout << a << ' ' << b << ' ' << rv << endl;
	return rv;		
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	
	n = rint();
	k = rint();
	v = VI(n);
	REP(i, n) cin >> v[i];
	cout << go(0, n-1) << endl;
	
	return 0;
}