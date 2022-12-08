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

#define MOD 1000000007

string s0, s1;
int n;
LL dp[1<<20][2][2];

int main() {
	cin >> n;
	cin >> s0 >> s1;
	
	// REP(i, n) s0[i] -= '0';
	// REP(i, n) s1[i] -= '0';
	
	dp[0][0][0] = 1;
	REP(i, n) REP(a, 2) REP(b, 2) {
		REP(d0, 10) REP(d1, 10) {
			if (s0[i] != '?' && d0 + '0' != s0[i]) continue;
			if (s1[i] != '?' && d1 + '0' != s1[i]) continue;
			if (d0 == d1) {
				dp[i+1][a][b] = (dp[i+1][a][b] + dp[i][a][b]) % MOD;
			} else if (d0 < d1) {
				dp[i+1][1][b] = (dp[i+1][1][b] + dp[i][a][b]) % MOD;
			} else {
				dp[i+1][a][1] = (dp[i+1][a][1] + dp[i][a][b]) % MOD;
			}
		}
	}
	
	cout << dp[n][1][1] << endl;
}