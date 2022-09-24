#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

// Parametric Self-Dual Simplex Method;
// min. cx;
// s.t. Ax <= b;
//       x >= 0;
typedef vector<double> Array;
typedef vector<Array> Matrix;

const double EPS = 1e-6, INF = 1./0.;

double simplex_method(const Matrix &A, const Array &B, const Array &C, Array &X) {
    int m = A.size(), n = A[0].size();
    double T[m+1][n+m+1];
    memset(T, 0, sizeof(T));
    X.clear();
    VI basic(m);
    REP(j, m) {
	REP(i, n) T[j][i] = A[j][i];
	T[j][n+j] = 1;
	T[j][n+m] = B[j];
	basic[j] = j+n;
    }
    REP(i, n) T[m][i] = C[i];
    while (1) { 
	int p = 0, q = 0;
	REP(i, n+m) if (T[m][i] <= T[m][p]) p = i;
	REP(j, m) if (T[j][n+m] <= T[q][n+m]) q = j;
	double t = min(T[m][p], T[q][n+m]);
	if (t >= -EPS) {
	    X.resize(n);
	    fill(X.begin(), X.end(), 0.0);
	    REP (i, m) if (basic[i] < n) X[basic[i]] = T[i][n+m];
	    return -T[m][n+m]; // optimal
	}
	if (t < T[q][n+m]) { // tight on c -> primal update
	    REP(j, m) if (T[j][p] >= EPS) 
		if (T[j][p]*(T[q][n+m]-t) >= T[q][p]*(T[j][n+m]-t)) q = j;
	    if (T[q][p] <= EPS) return INF; // primal infeasible (no solution);
	} else { // tight on b -> dual update
	    REP(i, n+m+1) T[q][i] *= -1;
	    REP(i, n+m) if (T[q][i] >= EPS) 
		if (T[q][i]*(T[m][p]-t) >= T[q][p]*(T[m][i]-t)) p = i;
	    if (T[q][p] <= EPS) return -INF; // dual infeasible (negative infinity);
	}
	REP(i, m+n+1) if (i != p) T[q][i] /= T[q][p];
	T[q][p] = 1;
	basic[q] = p; // pivot(q, p)
	REP(j, m+1) if (j != q) {
	    double alpha = T[j][p];
	    REP(i, n+m+1) T[j][i] -= T[q][i] * alpha;
	}
    }
}

int N1, N2, M, RCost, BCost;
char S1[211];
char S2[211];

int U[211], V[211];
VI G1[211], G2[211];
char color[211];

void MAIN() {
    scanf("%d%d%d%d%d", &N1, &N2, &M, &RCost, &BCost);
    scanf("%s", S1);
    scanf("%s", S2);
    REP (i, M) {
	scanf("%d%d", U+i, V+i);
	U[i]--;
	V[i]--;
	G1[U[i]].push_back(i);
	G2[V[i]].push_back(i);
    }

    const int LEN = M*2;
    Matrix A;
    Array B;

    REP (i, M) {
	// x_i + y_i <= 1;
	Array a(LEN);
	a[i] = a[i+M] = 1;
	A.push_back(a);
	B.push_back(1);
    }

    REP (v, N1) {
	Array a(LEN);
	if (S1[v] == 'R') {
	    // sum (-x_i + y_i) <= -1
	    EACH (e, G1[v]) {
		a[*e] = -1;
		a[*e + M] = 1;
	    }
	    A.push_back(a);
	    B.push_back(-1);
	}
	if (S1[v] == 'B') {
	    // sum (x_i - y_i) <= -1
	    EACH (e, G1[v]) {
		a[*e] = 1;
		a[*e + M] = -1;
	    }
	    A.push_back(a);
	    B.push_back(-1);
	}
    }
    REP (v, N2) {
	Array a(LEN);
	if (S2[v] == 'R') {
	    // sum (-x_i + y_i) <= -1
	    EACH (e, G2[v]) {
		a[*e] = -1;
		a[*e + M] = 1;
	    }
	    A.push_back(a);
	    B.push_back(-1);
	}
	if (S2[v] == 'B') {
	    // sum (x_i - y_i) <= -1
	    EACH (e, G2[v]) {
		a[*e] = 1;
		a[*e + M] = -1;
	    }
	    A.push_back(a);
	    B.push_back(-1);
	}
    }

    Array C(LEN);
    REP (i, M) {
	C[i] = RCost;
	C[i+M] = BCost;
    }

    Array X;
    auto ans = simplex_method(A, B, C, X);
    if (ans == INF || ans == -INF) {
	puts("-1");
    } else {
	REP (i, M) {
	    if (X[i] >= 0.5) {
		color[i] = 'R';
	    } else if (X[i+M] >= 0.5) {
		color[i] = 'B';
	    } else {
		color[i] = 'U';
	    }
	}

	int cost = 0;
	REP (i, M) {
	    if (color[i] == 'R') cost += RCost;
	    if (color[i] == 'B') cost += BCost;
	}
	printf("%d\n", cost);
	puts(color);
	//eprintf("%f\n", ans);
    }
}

int main() {
    int TC = 1;
    //    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}