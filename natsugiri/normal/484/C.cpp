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
char S[1000111];
char buf[1000111];
int K, D;
VI Merge(VI x, VI y, int z) {
    VI r(N);
    REP (i, N) {
	if (x[i] < z) r[i] = x[i];
	else r[i] = y[x[i]-z]+z;
    }
    return r;
}
VI power(int y) {
    VI r(N), v(N);
    REP (i, N) r[i] = v[i] = i;
    VI w;
    REP (i, D) for (int j=i; j<K; j+=D) w.push_back(v[j]);
    REP (i, K) v[w[i]] = i;
    for (int i=0; (1<<i) <= y; i++) {
	if (y & (1<<i)) r = Merge(v, r, (1<<i));
	v = Merge(v, v, 1<<i);
    }
    return r;
}

int main() {
    scanf("%s", S);
    N = strlen(S);
    scanf("%d", &M);
    REP ($, M) {
	scanf("%d%d", &K, &D);
	VI r = power(N-K+1);
	REP (i, N) buf[r[i]] = S[i];
	REP (i, N) S[i] = buf[i];
	puts(S);
    }

    return 0;
}