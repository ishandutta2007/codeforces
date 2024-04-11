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

string read() {
    static char buf[111];
    scanf("%s", buf);
    return buf;
}

int N;
string A, B;

int main() {
    A = read();
    B = read();
    scanf("%d", &N);
    REP (i, N+1) {
	printf("%s %s\n", A.c_str(), B.c_str());
	if (i == N) break;

	string C = read();
	string D = read();
	if (A == C) swap(A, D);
	else if (B == C) swap(B, D);
    }
    return 0;
}