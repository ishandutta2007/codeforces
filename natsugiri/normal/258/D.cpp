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

int N, M, P[1011], A[1011], B[1011];
double G[1011][1011];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) { scanf("%d", P+i); P[i]--; }
    REP (i, M) { 
	scanf("%d%d", A+i, B+i);
	A[i]--; B[i]--;
	if (A[i] > B[i]) swap(A[i], B[i]);
    }

    REP (i, N) REP (j, N) if (P[i] > P[j]) G[i][j] = 1;

    REP (i, M) {
	int a = A[i], b = B[i];
	REP (x, N) if (x != a && x != b) {
	    double k, l;
	    k = (G[x][a] + G[x][b]) * 0.5;
	    l = (G[a][x] + G[b][x]) * 0.5;
	    G[x][a] = G[x][b] = k;
	    G[a][x] = G[b][x] = l;
	}
	G[a][b] = G[b][a] = (G[a][b] + G[b][a]) * 0.5;
    }

    double ans = 0;
    REP (i, N) REP (j, N) if (i < j) ans += G[i][j];
    printf("%.9f\n", ans);

    return 0;
}