#include<cassert>
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

vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}
int N;
string A[3011];
string B[3011];
int L[3011], R[3011];
bool same[3011];
char buf[3011];
VI idx;

string from, to;

bool test1() {
    EACH (e, idx) {
	int i = *e;
	if ((int)from.size() != R[i] - L[i]) {
	    return false;
	}

	if (A[i].compare(L[i], R[i] - L[i], from) != 0) {
	    return false;
	}
	if (B[i].compare(L[i], R[i] - L[i], to) != 0) {
	    return false;
	}
    }
    return true;
}

void growR() {
    while (1) {
	char c = '$';
	EACH (e, idx) {
	    int i = *e;
	    if (R[i] == (int)A[i].size()) return;
	    c = A[i][R[i]];
	}
	EACH (e, idx) {
	    int i = *e;
	    if (c != A[i][R[i]]) return;
	}
	EACH (e, idx) {
	    int i = *e;
	    R[i]++;
	}
    }
}

void growL() {
    while (1) {
	char c = '$';
	EACH (e, idx) {
	    int i = *e;
	    if (L[i] == 0) return;
	    c = A[i][L[i]-1];
	}
	EACH (e, idx) {
	    int i = *e;
	    if (c != A[i][L[i]-1]) return;
	}
	EACH (e, idx) {
	    int i = *e;
	    L[i]--;
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	A[i] = buf;
    }
    REP (i, N) {
	scanf("%s", buf);
	B[i] = buf;
    }

    REP (i, N) same[i] = (A[i] == B[i]);
    REP (i, N) if (!same[i]) {
	idx.push_back(i);
    }

    EACH (e, idx) {
	int i = *e;
	int l = -1, r = -1;
	REP (j, A[i].size()) {
	    if (A[i][j] != B[i][j]) {
		if (l == -1) l = j;
		r = j + 1;
	    }
	}
	L[i] = l;
	R[i] = r;
    }

    EACH (e, idx) {
	int i = *e;
	from = A[i].substr(L[i], R[i] - L[i]);
	to = B[i].substr(L[i], R[i] - L[i]);
	break;
    }

    bool yes = test1();
    if (yes) {
	growL();
	growR();

	EACH (e, idx) {
	    int i = *e;
	    from = A[i].substr(L[i], R[i] - L[i]);
	    to = B[i].substr(L[i], R[i] - L[i]);
	    break;
	}

	string P = from;
	REP (i, N) {
	    P += A[i];
	}
	VI Z = Z_Algorithm(P);

	int cur = from.size();
	REP (i, N) {
	    int nxt = cur + (int)A[i].size();
	    for (int j=0, pos=cur; pos+(int)from.size()<=nxt; pos++, j++) {
		if (Z[pos] >= (int)from.size()) {
		    if (same[i]) {
			yes = false;
		    } else {
			if (j != L[i]) {
			    yes = false;
			}
		    }

		    break;
		}
	    }

	    cur = nxt;
	}
//	assert(cur == (int)Z.size());
    }

    if (yes) {
	puts("YES");
	printf("%s\n", from.c_str());
	printf("%s\n", to.c_str());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}