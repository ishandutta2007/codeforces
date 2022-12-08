#include <bits/stdc++.h>
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

const int MAX_TIME = 20000000;

short a1[MAX_TIME];
short a2[MAX_TIME];
short a3[MAX_TIME];

int main() {
	int k;
	int n1, n2, n3;
	int t1, t2, t3;
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	REP(i, MAX_TIME) a1[i] = n1;
	REP(i, MAX_TIME) a2[i] = n2;
	REP(i, MAX_TIME) a3[i] = n3;
	int rv = 0;
	REP(i, k) {
		bool ok = true;
		ok &= a1[rv] > 0;
		ok &= a2[rv + t1] > 0;
		ok &= a3[rv + t1 + t2] > 0;
		if (!ok) {
			i--;
			rv++;
			continue;
		}
		REP(j, t1) a1[rv + j]--;
		REP(j, t2) a2[rv + t1 + j]--;
		REP(j, t3) a3[rv + t1 + t2 + j]--;
	}
	cout << (rv + t1 + t2 + t3) << endl;
	return 0;
}