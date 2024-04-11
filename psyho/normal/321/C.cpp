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

VI cn[101000];
int vs[101000];
int n;

int go(int x, int p = -1) {
	int v = 0;
	int bad = 0;
	REP(i, cn[x].S) if (cn[x][i] != p) {
		int z = go(cn[x][i], x);
		bad |= v & z;
		v |= z;
	}
	for (int i = 25; i >= 0; i--) {
		if ((v & (1 << i)) == 0 && bad == 0) {
			FOR(j, i + 1, 25 + 1) v &= ~(1 << j);
			vs[x] = i;
			v += 1 << i;
			break;
		}
		bad &= ~(1 << i);
		if (i == 0) throw 1;
	}
	//cout << x << ' ' << vs[x] << endl;
	return v;
}

int main() {
	cin >> n;
	REP(i, n-1) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		cn[a].PB(b);
		cn[b].PB(a);
	}
	
	int mn = 100, mx = 0;
	try {
		go(0);
	} catch (int e) {
		mx = 100;
	}
	
	REP(i, n) mn = min(mn, vs[i]), mx = max(mx, vs[i]);
	if (mx > 25) {
		cout << "Impossible!" << endl;
		return 0;
	}
	REP(i, n) cout << (char)('A'+vs[i]-mn) << ' ';
	cout << endl;
	
	return 0;
}