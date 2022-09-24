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

int N, M;
int P[20111];
pair<int, int> sortP[20111];
int A[10111], B[10111];

int S[20111];
bool use[20111];
int pre = -1;

void query(int i) {
    printf("%d\n", i+1);
    fflush(stdout);
    use[i] = true;
}

void enemy() {
    int x;
    scanf("%d", &x);
    x--;
    pre = x;
    use[x] = true;
}


void MAIN() {
    memset(S, -1, sizeof S);

    scanf("%d%d", &N, &M);
    REP (i, N*2) scanf("%d", P+i);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
	S[A[i]] = B[i];
	S[B[i]] = A[i];
    }

    int turn;
    scanf("%d", &turn);

    REP (i, N*2) sortP[i] = make_pair(P[i], i);
    sort(sortP, sortP+N*2);
    reverse(sortP, sortP+N*2);

    int ab_index = 0;
    int sortp_index = 0;

    REP ($, N*2) {
	if (turn == 1) {
	    if (pre != -1 && S[pre] != -1 && !use[S[pre]]) {
		query(S[pre]);
	    } else {
		while (ab_index < M) {
		    if (!use[A[ab_index]]) break;
		    ab_index++;
		}
		if (ab_index < M) {
		    int a = A[ab_index];
		    int b = B[ab_index];
		    if (P[a] > P[b]) query(a);
		    else query(b);
		} else {
		    while (sortp_index < N*2 && use[sortP[sortp_index].second]) sortp_index++;
		    query(sortP[sortp_index].second);
		}
	    }
	} else {
	    enemy();
	}

	turn ^= 3;
    }

//    assert(ab_index == M);
//    assert(sortp_index == N*2);
    REP (i, N*2) assert(use[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}