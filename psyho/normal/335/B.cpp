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

int dp[3000][3000];
int bm[3000][3000];

string s;
int go(int a, int b) {
	int &rv = dp[a][b];
	if (rv != -1) return rv;
	if (a > b) return rv = 0;
	if (a == b) return rv = 1;
	rv = -1;
	if (go(a + 1, b) > rv) {
		rv = go(a + 1, b);
		bm[a][b] = -1;
	}
	if (go(a, b - 1) > rv) {
		rv = go(a, b - 1);
		bm[a][b] = 1;
	}
	if (s[a] == s[b] && go(a + 1, b - 1) + 2 > rv) {
		rv = 2 + go(a + 1, b - 1);
		bm[a][b] = 0;
	}
	return rv;
}

int main() {
	cin >> s;
	if (s.S >= 3000) {
		REP(i, 26) {
			int no = 0;
			REP(j, s.S) no += s[j] == i + 'a';
			if (no >= 100) {
				REP(j, 100) cout << (char)('a'+i);
				cout << endl;
				return 0;
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	memset(bm, -2, sizeof(bm));
	go(0, s.S - 1);
	string rv = "";
	int a = 0;
	int b = (int)s.S - 1;
	while (a < b) {
		if (bm[a][b] == -1) {
			a++;
		} else if (bm[a][b] == 1) {
			b--;
		} else if (bm[a][b] == 0) {
			rv += s[a];
			a++;
			b--;
		} else {
		}
	}
	
	if (rv.S >= 50) {
		rv = rv.substr(0, 50);
		a = 0, b = 1;
	}
	string rr = rv;
	reverse(ALL(rr));
	rv = rv + (a == b ? string(1, s[a]) : string()) + rr;
	cout << rv << endl;
	return 0;
}