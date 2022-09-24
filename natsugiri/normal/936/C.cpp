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
char S[2111], T[2111];
char B[2111];
int C[26];

VI ans;
void Shift(int x) {
    if (x <= 0) return;
    REP (i, x) B[i] = S[N-1-i];
    REP (i, N-x) B[i+x] = S[i];
    REP (i, N) S[i] = B[i];
    ans.push_back(x);
}
void MAIN() {
    scanf("%d", &N);
    scanf("%s%s", S, T);
    REP (i, N) {
	C[S[i]-'a']++;
	C[T[i]-'a']--;
    }
    REP (c, 26) if (C[c]) {
	puts("-1");
	return ;
    }

    int len = 0;
    while (len<N) {
	// S[0] <- T[len];
	int pos;
	for (pos=0; ; pos++) if (S[pos] == T[len]) break;
	Shift(N-pos-1);
	Shift(1);
	len++;
	Shift(N);
	if (len == N) break;
    }
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
//    eprintf("%s\n", S);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}