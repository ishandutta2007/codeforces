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

int n1, n2, k;
LL dp[60][60][220];
LL ok[60][60][220];
LL ch[100][100];

int best = 210;

LL go(int a1, int a2, int t) {
	LL &rv = dp[a1][a2][t];
	if (rv != -1) return rv;
	
	if (t > best) return rv = 0;
	
	// cout << a1 << ' ' << a2 << ' ' << t << endl;
	if (a1 == 0 && a2 == 0) {
		best = min(best, t);
		ok[a1][a2][t] = 1;
		return rv = 1;
	}
	
	int b1 = n1 - a1;
	int b2 = n2 - a2;
	
	rv = 0;
	
	if (t % 2 == 0) {
		REP(i1, a1 + 1) REP(i2, a2 + 1) if (i1 + i2 * 2 <= k && (i1 || i2)) {
			go(a1 - i1, a2 - i2, t + 1);
			if (ok[a1 - i1][a2 - i2][t + 1]) {
				ok[a1][a2][t] = 1;
				dp[a1][a2][t] = (dp[a1][a2][t] + (((LL)ch[i1][a1] * ch[i2][a2]) % MOD) * dp[a1-i1][a2-i2][t+1]) % MOD;
			}
		}
	} else {
		REP(i1, b1 + 1) REP(i2, b2 + 1) if (i1 + i2 * 2 <= k && (i1 || i2)) {
			go(a1 + i1, a2 + i2, t + 1);
			if (ok[a1 + i1][a2 + i2][t + 1]) {
				ok[a1][a2][t] = 1;
				dp[a1][a2][t] = (dp[a1][a2][t] + (((LL)ch[i1][b1] * ch[i2][b2]) % MOD) * dp[a1+i1][a2+i2][t+1]) % MOD;
			}
		}
	}
	
	return rv;
}


int main() {

	ch[0][0] = 1;
	FOR(i, 1, 51) {
		ch[0][i] = 1;
		FOR(j, 1, i + 1) ch[j][i] = (ch[j][i-1] + ch[j-1][i-1]) % MOD;
	}
	
	
	int n;
	cin >> n >> k;
	REP(i, n) {
		int x;
		cin >> x;
		if (x == 50) n1++; else n2++;
	}
	k /= 50;
	
	memset(dp, -1, sizeof(dp));
	go(n1, n2, 0);
	
	if (best < 210) {
		memset(dp, -1, sizeof(dp));
		ZERO(ok);
		go(n1, n2, 0);
		cout << best << endl << dp[n1][n2][0] << endl;
	} else {
		cout << -1 << endl << 0 << endl;
	}
}