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

int N;
int A[100111], B[100111];
int C[100111];

int main() {
    scanf("%d", &N);
    vector<pair<int, int> > root;
    REP (i, N-1) scanf("%d%d", A+i, B+i), A[i]--, B[i]--;
    REP (i, N) scanf("%d", C+i);
    REP (i, N-1) {
	int x = A[i], y = B[i];
	if (C[x] != C[y]) {
	    root.push_back(make_pair(x, y));
	}
    }

    if (root.empty()) {
	puts("YES");
	puts("1");
	return 0;
    } else {
	REP (t, 2) {
	    int v = (t ? root[0].first: root[0].second);
	    bool yes = true;
	    EACH (e, root) {
		if (e->first != v && e->second != v) {
		    yes = false;
		    break;
		}
	    }

	    if (yes) {
		puts("YES");
		printf("%d\n", v + 1);
		return 0;
	    }
	}

	puts("NO");
    }


    return 0;
}