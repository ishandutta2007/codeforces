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

int a[1000];
int vs[1000];
int p[1000];
int dp[1100][1100];
int main() {
	int n, k;
	cin >> n >> k;
	memset(p, -1, sizeof(p));
	REP(i, n) {
		cin >> a[i];
		if (a[i]) p[a[i]-1] = i;
	}
	
	VI sz;
	
	int opos = -1;
	k--;
	REP(i, n) if (a[i] == 0) {
		int x = i;
		int no = 1;
		int f = 0;
		do {
			if (x == k) {
				opos = no;
				f = 1;
			}
			if (p[x] == -1) break;
			x = p[x];
			no++;
		} while (true);
		if (!f) sz.PB(no);
	}
	ZERO(dp);
	dp[0][opos] = 1;
	REP(j, sz.S) {
		int v = sz[j];
		for (int i = n-v; i >=0; i--) {
			dp[j+1][i+v] |= dp[j][i];
			dp[j+1][i] |= dp[j][i];
		}
	}
	FOR(i, 1, n+1) if (dp[sz.S][i]) {
		cout << i << endl;
	}
}