#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
int V;
VI L, E;

int get_left(const VI &v, int y) {
    int k = upper_bound(v.begin(), v.end(), y) - v.begin();
    if (k) return v[k-1];
    else return -1;
}
int get_right(const VI &v, int y) {
    int k = lower_bound(v.begin(), v.end(), y) - v.begin();
    if (k < (int)v.size()) return v[k];
    else return -1;
}

void MAIN() {
    int Cl, Ce;
    scanf("%d%d%d%d%d", &N, &M, &Cl, &Ce, &V);

    L.reserve(Cl);
    REP (i, Cl) {
	int x;
	scanf("%d", &x);
	L.push_back(x);
    }
    E.reserve(Ce);
    REP (i, Ce) {
	int x;
	scanf("%d", &x);
	E.push_back(x);
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int X1, Y1, X2, Y2;
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	if (Y1 > Y2) {
	    swap(X1, X2);
	    swap(Y1, Y2);
	}

	int ans = 1<<29;
	if (X1 == X2) {
	    ans = Y2 - Y1;
	} else {

	    REP (t, 2) {
		const VI &ar = (t? L: E);
		int v = (t? 1: V);
		REP (u, 2) {
		    int y = (u? Y1: Y2);

		    int pos = get_left(ar, y);
		    if (pos != -1) {
			int tmp = abs(Y1 - pos) + (abs(X1-X2) + v - 1) / v + abs(pos - Y2);
			amin(ans, tmp);
		    }

		    pos = get_right(ar, y);
		    if (pos != -1) {
			int tmp = abs(Y1 - pos) + (abs(X1-X2) + v - 1) / v + abs(pos - Y2);
			amin(ans, tmp);
		    }
		}
	    }
	}
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}