#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M, Q;
int A[1011][1011];
int R[1011111], D[1011111];

VI get(int a, int b, int h, int w) {
    int cur = 0;
    VI ret;
    REP (i, a-1) cur = D[cur];
    REP (i, b-1) cur = R[cur];

    int x = cur;
    REP (i, h) {
	x = D[x];
	ret.push_back(x);
    }
    REP (i, w) {
	x = R[x];
	ret.push_back(x);
    }
    x = cur;
    REP (i, w) {
	x = R[x];
	ret.push_back(x);
    }
    REP (i, h) {
	x = D[x];
	ret.push_back(x);
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);

    REP (i, N) REP (j, M) scanf("%d", &A[i+1][j+1]);

    N+=2; M+=2;
    REP (i, N) REP (j, M) {
	R[i * M + j] = i * M + j + 1;
	D[i * M + j] = (i + 1) * M + j;
    }
    REP ($, Q) {
	int a, b, c, d, h, w;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
	VI e = get(a, b, h, w);
	VI f = get(c, d, h, w);

	for (int i=0; i<h; i++)
	    swap(R[e[i]], R[f[i]]);
	for (int i=h; i<h+w; i++)
	    swap(D[e[i]], D[f[i]]);
	for (int i=h+w; i<h+w+w; i++)
	    swap(D[e[i]], D[f[i]]);
	for (int i=h+w+w; i<h+w+h+w; i++)
	    swap(R[e[i]], R[f[i]]);
    }

    int cur = 0;
    REP (i, N-2) {
	cur = D[cur];
	int x = cur;
	REP (j, M-2) {
	    x = R[x];
	    int a = x / M;
	    int b = x % M;
	    printf("%d ", A[a][b]);
	}
	puts("");
    }


    return 0;
}