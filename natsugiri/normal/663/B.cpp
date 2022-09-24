#include<sstream>
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

int N;
char buf[101];

// 1989 9
// -
// 1990 0
// .......
// 1998 8

// 1999 99
// -
// 2000 00
// .......
// 2098 98

// 2099 099
// 2100 100
// ........
// 2999 999
// -
// 3000 000
// 3098 098

// 3099 3099
// 3100 3100
// .........
// 9999 9999
// -
// 10000 0000
// 13098 3098

// 13099 13099
// ...........
// 113098 13098

// 113099 113099


LL BASE[11] = { 0, 1980, 1900, 2000,     0,       0};
LL CUT[11] =  { 0,    9,   99,   99,  3099,  13099 };
LL ADD[11] =  { 0,   10,  100, 1000, 10000, 100000 };


int main() {
    for (int i=5; i<=10; i++) {
	ADD[i] = ADD[i-1] * 10;
	CUT[i] = CUT[i-1] + ADD[i-1];
    }
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	LL x;
	sscanf(buf + 4, "%lld", &x);
	int l = strlen(buf+4);
	LL ans = BASE[l] + x + (x < CUT[l]? ADD[l] : 0);
	printf("%lld\n", ans);
    }
    return 0;
}