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

int K;
int A[100111];
string s;
char buf[100111];

int eval() {
    int ret = 0;
    REP (i, s.size()) {
	if (i == 0 || s[i-1] == '+') ret += A[i];
	else ret -= A[i];
    }
    return ret;
}

int main() {
    while (1) {
	scanf("%s", buf);
	if (buf[0] == '?') {
	} else {
	    s.push_back(buf[0]);
	    if (buf[0] == '=') break;
	}
    }
    scanf("%d", &K);

    REP (i, s.size()) {
	if (i == 0 || s[i-1] == '+') A[i] = K;
	else A[i] = 1;
    }

    int x = eval();
    while (K < x) {
	int g = x - K;
	REP (i, s.size()) {
	    if (i == 0 || s[i-1] == '+') {
		int t = min(g, A[i] - 1);
		g -= t;
		A[i] -= t;
	    } else {
		int t = min(g, K - A[i]);
		g -= t;
		A[i] += t;
	    }
	}

	if (g == x - K) break;
	x = eval();
    }

    if (x == K) {
	puts("Possible");
	REP (i, s.size()) printf("%d %c ", A[i], s[i]);
	printf("%d\n", K);
    } else {
	puts("Impossible");
    }

    return 0;
}