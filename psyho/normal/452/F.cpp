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

bool checkfull(VI &v) {
	int n = v.S;
	REP(i, n) REP(j, i) {
		int x = v[i] + v[j];
		if (x & 1) continue;
		x /= 2;
		FOR(k, j + 1, i) if (v[k] == x) {
			return true;
		}
	}
	return false;
}

bool check(VI &v) {
	if (v.S <= 2) return false;
	
	{
		VI u((v.S + 1) / 2);
		int p = 0;
		REP(i, v.S) if (v[i] & 1) u[p++] = (v[i] + 1) / 2;
		if (check(u)) return true;
	}

	{
		VI u(v.S / 2);
		int p = 0;
		REP(i, v.S) if ((v[i] & 1) == 0) u[p++] = v[i] / 2;
		if (check(u)) return true;
	}

	int gmn = 1;
	int gmx = v.S;
	if (v[0] % 2) {
		REP(i, v.S) v[i]++;
		gmn++;
		gmx++;
	}
	
	int pno = 0;
	REP(i, v.S) pno += (v[i] & 1) == 0;
	
	{
		int mn = 1 << 20;
		int mx = -(1 << 20);
		REP(i, v.S) {
			if (v[i] & 1) {
				mn = min(mn, v[i]);
				mx = max(mx, v[i]);
			} else {
				int a;
				a = v[i] * 2 - mn;
				if (a >= gmn && a <= gmx) {
					// print(v);
					return true;
				}
				a = v[i] * 2 - mx;
				if (a >= gmn && a <= gmx) {
					// print(v);
					return true;
				}
			}
		}
	}
	
	{
		int mn = 1 << 20;
		int mx = -(1 << 20);
		for (int i = v.S - 1; i >= 0; i--) {
			if ((v[i] & 1) == 0) {
				mn = min(mn, v[i]);
				mx = max(mx, v[i]);
			} else {
				int a;
				a = v[i] * 2 - mn;
				if (a >= gmn && a <= gmx) {
					// print(v);
					return true;
				}
				a = v[i] * 2 - mx;
				if (a >= gmn && a <= gmx) {
					// print(v);
					return true;
				}
			}
		}
	}
	
	return false;
}

void validate(int n) {
	VI v(n);
	REP(i, n) v[i] = i + 1;
	do {
		VI nv(ALL(v));
		if (check(nv) != checkfull(v)) {
			cout << checkfull(v) << ' '; print(v);
		}
	} while (next_permutation(ALL(v)));
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	VI v = VI(n);
	REP(i, n) cin >> v[i];
	cout << (check(v) ? "YES" : "NO") << endl;
	
	
	return 0;
}