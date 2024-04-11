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

int main() {
	string s;
	cin >> s;
	
	int zeros = 0;
	VI letters(10);
	int rv = 1;
	REP(i, s.S) {
		if (s[i] == '?') zeros++;
		if (s[i] >= 'A' && s[i] <= 'J') letters[s[i]-'A']++;
	}
	
	LL x = 1;
	
	if (s[0] == '?') {
		zeros--;
		x *= 9;
	}
	
	int y = 0;
	REP(i, 10) y += letters[i] > 0;
	
	REP(i, y) x *= (i == 0 && s[0] >= 'A' && s[0] <= 'Z') ? 9 : 10 - i;
	
	cout << x;
	if (x) REP(i, zeros) cout << '0';
	cout << endl;

	
}