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
int main() {
	LL rv = 0;
	cin >> n >> m;
	VI atk, def, v;
	REP(i, n) {
		string s;
		int x;
		cin >> s >> x;
		if (s[0] == 'A') atk.PB(x); else def.PB(x);
	}
	REP(i, m) {
		int x;
		cin >> x;
		v.PB(x);
	}
	sort(ALL(atk));
	sort(ALL(def));
	sort(ALL(v));
	
	VI xatk = atk, xdef = def, xv = v;
	
	reverse(ALL(v));
	REP(i, min(v.S, atk.S)) rv += max(0, v[i] - atk[i]); 
	
	LL av = 0;
	reverse(ALL(v));
	REP(i, def.S) {
		REP(j, v.S) if (v[j] > def[i]) {
			v.erase(v.begin() + j);
			goto ok1;
		}
		goto done;
		ok1: ;
	}
	REP(i, atk.S) {
		REP(j, v.S) if (v[j] >= atk[i]) {
			av += v[j] - atk[i];
			v.erase(v.begin() + j);
			goto ok2;
		}
		goto done;
		ok2: ;
	}
	REP(i, v.S) av += v[i];
	
	
	done: ;
	rv = max(av, rv);
	cout << rv << endl;
	return 0;
}