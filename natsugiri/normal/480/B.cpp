#include<set>
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

int N, L, D[2];
int A_[100111];

int main() {
    scanf("%d%d%d%d", &N, &L, D, D+1);
    REP (i, N) scanf("%d", A_+i);

    set<int> se(A_, A_+N);

    VI v;
    REP (i, 2) {
	bool yes = false;

	EACH (e, se) {
	    if (se.find(D[i] + *e) != se.end() || se.find(*e - D[i]) != se.end()) {
		yes = true;
		break;
	    }
	}
	if (!yes) v.push_back(D[i]);
    }


    if (v.empty()) {
	puts("0");
    } else if (v.size() == 1u) {
	printf("1\n%d\n", v[0]);
    } else {
	// x, p, q : (p-x, q-x)
	// p, x, q : (x-p, q-x), (q-x, x-p)
	// p, q, x : (x-q, x-p)
	int ans = -1;
	EACH (e, se) {
	    int x[] = { *e - D[0], *e + D[0], *e + D[1], *e + D[1] };
	    int y[] = { x[0] + D[1], x[1] + D[1], x[2] + D[0], x[3] - D[0] };
	    REP (i, 4) {
		if (0 <= x[i] && x[i] <= L && se.find(y[i]) != se.end()) {
		    ans = x[i];
		    break;
		}
	    }
	    if (ans != -1) break;
	}

	if (ans == -1) {
	    puts("2");
	    rprintf("%d", D, D+2);
	} else {
	    printf("1\n%d\n", ans);
	}
    }
    

    return 0;
}