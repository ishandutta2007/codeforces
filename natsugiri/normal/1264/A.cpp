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

int N;
int A[400011];
VI v;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int g, s, b;
    g = s = b = 0;

    v.clear();
    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && A[i] == A[j]) j++;
	v.emplace_back(j-i);
	i = j;
    }

    g = v[0];
    int i=1;
    while (i < (int)v.size() && s <= g) {
	s += v[i];
	i++;
    }
    while (i < (int)v.size() && b <= g) {
	b += v[i];
	i++;
    }
    while (i < (int)v.size() && (g+s+b+v[i])*2 <= N) {
	b += v[i];
	i++;
    }

    if (g && s && b && g < s && g < b && (g+s+b)*2 <= N) {
	printf("%d %d %d\n", g, s, b);
    } else {
	puts("0 0 0");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}