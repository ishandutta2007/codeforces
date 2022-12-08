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

int cnt[26];
int no[26];
int main() {
	string s;
	int n;
	cin >> s >> n;
	REP(i, s.S) cnt[s[i]-'a']++;
	
	string rv = "";
	int pos = 0;
	REP(i, 26) pos += cnt[i] > 0;
	if (pos > n) {
		cout << -1 << endl;
		return 0;
	}
	
	REP(i, 26) if (cnt[i] > 0) no[i]++, n--;
	while (n) {
		int bb = -1;
		REP(i, 26) if (cnt[i] && (bb == -1 || (cnt[i] + no[i] - 1) / no[i] > (cnt[bb] + no[bb] - 1) / no[bb])) bb = i;
		no[bb]++;
		n--;
	}
	
	int tt = 0;
	REP(i, 26) if (cnt[i]) tt = max(tt, (cnt[i] + no[i] - 1) / no[i]);
	REP(i, 26) REP(j, no[i]) rv += (char)('a' + i);
	cout << tt << endl << rv << endl;
	return 0;
}