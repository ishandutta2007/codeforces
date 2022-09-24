#include<queue>
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
int A[100111];
int B[100111];
int K[200111];
bool F[100111];
bool in[200111];
queue<int> qu;

inline int get(int x) {
    if (x < N) return F[x];
    return !F[x - N];
}

inline void flip(int x) {
    int y = x % N;
    F[y] = !F[y];

    REP (a, 2) {
	int t = (a? A[y]: B[y]);
	for (int i=t-2; i<=t; i++) {
	    int k = (i+2*N) % (2*N);
	    if (!in[k]) {
		in[k] = true;
		qu.push(k);
	    }
	}
    }
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, B+i), A[i]--, B[i]--;

    REP (i, N) {
	K[A[i]] = i;
	K[B[i]] = i + N;
	F[i] = rand() & 1;
    }

//    N = 100000;
//    REP (i, 2 * N) K[i] = i;
//    random_shuffle(K, K + 2 * N);
//    REP (i, 2 * N) eprintf("%d ", K[i]); eprintf("\n");

    if (N <= 2) {
	REP (i, N) puts("1 2");
	return 0;
    }

    REP (i, 2 * N) {
	qu.push(i);
	in[i] = true;
    }

    while (!qu.empty()) {
	int i = qu.front(); qu.pop();
	in[i] = false;
	int a = K[i], b = K[(i+1) % (2*N)], c = K[(i+2) % (2*N)];
	int s = get(a) + get(b) + get(c);
	if (s == 0 || s == 3) {
	    int k = rand() % 3;
	    if (k == 0) flip(a);
	    else if (k == 1) flip(b);
	    else flip(c);
	}
    }

    REP (i, N) printf("%d %d\n", get(i) + 1, 2 - get(i));

    return 0;
}