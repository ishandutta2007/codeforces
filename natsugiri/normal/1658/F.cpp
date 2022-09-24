#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, M;
char S[200011];

pair<int, int> run(int start, int tar0, int tar1) {
    if (start + tar0 + tar1 > N) return make_pair(-1, -1);

    int cur0 = 0, cur1 = 0;
    int i = start;
    for (int k=0; k<tar0 + tar1; k++, i++) {
	if (S[i] == '0') cur0++;
	else cur1++;
    }

    for (int j=start; i<=N; i++, j++) {
	if (cur0 == tar0) return make_pair(j, i);

	if (i == N) break;

	if (S[i] == '0') cur0++;
	else cur1++;
	if (S[j] == '0') cur0--;
	else cur1--;
    }
    return make_pair(-1, -1);
}

void MAIN() {
    scanf("%d%d%s", &N, &M, S);


    int one = count(S, S+N, '1');

    int T = (LL)one * M / N;
    if ((LL)N * T != (LL)M * one) {
	puts("-1");
	return;
    }

    pair<int, int> p = run(0, M-T, T);
    if (p.first != -1) {
	puts("1");
	printf("%d %d\n", p.first+1, p.second);
	return;
    }

    int cur0 = 0, cur1 = 0;
    int i = 0;
    for (; i<M; i++) {
	if (S[i] == '0') {
	    if (cur0 + 1 <= M - T) {
		cur0++;
	    } else {
		break;
	    }
	} else {
	    if (cur1 + 1 <= T) {
		cur1++;
	    } else {
		break;
	    }
	}
    }
    // eprintf("[%d %d]\n", cur0, cur1);

    for (; i>=0; i--) {
	pair<int, int> q = run(i, M-T-cur0, T-cur1);
	if (q.first != -1) {
	    puts("2");
	    printf("1 %d\n", i);
	    printf("%d %d\n", q.first+1, q.second);
	    return;
	}

	if (S[i-1] == '0') cur0--;
	else cur1--;
    }
    puts("-1");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}