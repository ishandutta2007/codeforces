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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, E, T;
int A[100111], B[100111];

VI G[50011];
int Z[50111];
bool C[1000111];


void team() {
    REP (i, N) Z[i] = G[i][rand() % G[i].size()];
}
void conf() {
    REP (i, T) C[i] = rand() & 1;
}
int eval() {
    int ret = 0;
    REP (i, E) {
	if (C[Z[A[i]]] != C[Z[B[i]]]) ret++;
    }
    return ret;
}
void show() {
    REP (i, N) printf("%d%c", Z[i]+1, i==N-1?'\n': ' ');
    REP (i, T) printf("%d%c", (int)C[i]+1, i==T-1?'\n':' ');
}

int main() {
    scanf("%d%d", &N, &E);
    REP (i, E) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	A[i] = x;
	B[i] = y;
    }

    REP (i, N) {
	int L;
	scanf("%d", &L);
	G[i].resize(L);
	REP (j, L) {
	    scanf("%d", &G[i][j]);
	    G[i][j]--;
	    amax(T, G[i][j]+1);
	}
    }


    team();
    conf();
    while (eval() * 2 < E) {
	if (rand() % 10 < 8) {
	    team();
	} else {
	    conf();
	}
    }

    show();
//    eprintf("%d\n", eval());


    return 0;
}