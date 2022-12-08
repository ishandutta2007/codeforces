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

#define MOD 1000000007
LL dp[1000000];
int a[1000000];
int n;

LL sum[3000000];


void update(int p, LL v) {
	p += 1 << 20;
	sum[p] = v;
	while (p > 1) {
		p /= 2;
		sum[p] = (sum[2*p] + sum[2*p+1]) % MOD;
	}
}

LL calc(int p) {
	LL rv = 0;
	p += 1 << 20;
	while (p > 1) {
		if (p % 2) rv -= sum[p-1];
		p /= 2;
	}
	rv += sum[1];
	
	rv = (rv % MOD + MOD) % MOD;
	return rv;
}

LL go(int p) {
	LL &rv = dp[p];
	if (rv != -1) return rv;
	
	rv = p == 0 ? 0 : 1;
	
	rv += calc(a[p]);
	rv *= a[p];
	rv %= MOD;
	
	update(a[p], rv);
	return rv;
}


int main() {
	cin >> n;
	a[0] = 1;
	REP(i, n) scanf("%d", &a[i+1]);
	n++;
	memset(dp, -1, sizeof(dp));
	
	for (int i = n - 1; i >= 1; i--) go(i);
	
	cout << go(0) << endl;
	return 0;
}