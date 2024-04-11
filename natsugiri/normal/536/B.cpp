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

typedef unsigned long long ULL;
const ULL UMOD = 1e9 + 7;
ULL powMod(ULL x, ULL y) {
    ULL r = 1;
    for (; y; y>>=1) {
	if (y & 1) r = r * x % UMOD;
	x = x * x % UMOD;
    }
    return r;
}

int N, M;
char buf[1000111];
string P;
int A[1000111];
int C[1000111];

int main() {
    scanf("%d%d%s", &N, &M, buf);
    P = buf;
    int L = P.size();
    REP (i, M) scanf("%d", A+i), A[i]--;

    VI Z = Z_Algorithm(P);
    bool yes = true;
    REP (i, M-1) {
	int d = A[i] + L - A[i+1];
	if (d > 0 && Z[L-d] < d) {
	    yes = false;
	    break;
	}
    }

    if (yes) {
	REP (i, M) {
	    C[A[i]]++;
	    C[A[i]+L]--;
	}
	REP (i, N) C[i+1] += C[i];
	int cnt = count(C, C+N, 0);
	int ans = powMod(26, cnt);
	printf("%d\n", ans);
    } else {
	puts("0");
    }

    return 0;
}