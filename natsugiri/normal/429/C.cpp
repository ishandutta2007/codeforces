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
int A[101];
int sum[1 << 13];
bool dp[14][1 << 13][24];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    int cnt = count(A, A+N, 1);

    
    if (*max_element(A, A+N) != N || count(A, A+N, 1) < N / 2) {
	puts("NO");
	return 0;
    }

    if (N == 1) {
	puts(A[0] == 1? "YES": "NO");
	return 0;
    }

    sort(A, A+N);
    reverse(A, A+N);
    int m = N - cnt;
    sort(A, A+m);
    dp[0][0][0] = true;

    REP (i, m) sum[1<<i] += A[i];
    REP (i, m) REP (t, 1<<m) if (~t & (1<<i)) sum[t | (1<<i)] += sum[t];

    REP (i, m) REP (S, 1<<i) REP (o, cnt+1) if (dp[i][S][o]) {
	for (int sub=S; ; sub = (sub - 1) & S) {
	    int r = A[i] - sum[sub] - 1;
	    if (0 <= r && r + o <= cnt && 2 <= __builtin_popcount(sub) + r) {
		eprintf("%d %d %d\n", i+1, (S&~sub)|(1<<i), r+o);
		dp[i+1][(S&~sub) | (1<<i)][r+o] = true;
	    }

	    if (sub == 0) break;
	}
    }

    puts(dp[m][1<<(m-1)][cnt]? "YES": "NO");


    return 0;
}