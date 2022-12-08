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


int main() {
	set<PII> st;
	int n, m;
	cin >> n >> m;
	REP(i, 2) REP(j, 2) {
		if (i <= n && j <= m) st.insert(MP(i, j));
		if (n - i >= 0 && m - j >= 0) st.insert(MP(n-i, m-j));
	}
	st.insert(MP(n, 0));
	st.insert(MP(0, m));
	VC<PII> vp(ALL(st));
	
	VI rv;
	double bd = 0;
	REP(i, vp.S) REP(j, vp.S) REP(k, vp.S) REP(l, vp.S) if (j != i && k != i && k != j && l != i && l != j && l != k) {
		double d = 0;
		d += hypot(vp[i].X - vp[j].X, vp[i].Y - vp[j].Y);
		d += hypot(vp[j].X - vp[k].X, vp[j].Y - vp[k].Y);
		d += hypot(vp[k].X - vp[l].X, vp[k].Y - vp[l].Y);
		if (d > bd) {
			bd = d;
			rv.clear();
			rv.PB(i);
			rv.PB(j);
			rv.PB(k);
			rv.PB(l);
		}
	}
	
	REP(i, 4) cout << vp[rv[i]].X << ' ' << vp[rv[i]].Y << endl;
	return 0;
}