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


LL A[555][555];
int N;
LL R[555], C[555], D[2];
int Si, Sj;
int main() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) scanf("%lld", A[i] + j);

    if (N == 1) {
	puts("1");
	return 0;
    }

    bool yes = true;

    REP (i, N) REP (j, N) {
	if (A[i][j] == 0) {
	    Si = i;
	    Sj = j;
	}
	R[i] += A[i][j];
	C[j] += A[i][j];
    }



    LL sum = *max_element(R, R+N);
    LL ans = sum - R[Si];
    A[Si][Sj] = sum - R[Si];

    memset(R, 0, sizeof R);
    memset(C, 0, sizeof C);

    REP (i, N) REP (j, N) {
	R[i] += A[i][j];
	C[j] += A[i][j];
    }

    REP (i, N) {
	if (R[i] != sum) yes = false;
	if (C[i] != sum) yes = false;

	D[0] += A[i][i];
	D[1] += A[i][N-1-i];
    }

    if (sum != D[0] || sum != D[1]) yes = false;

    if (yes && ans > 0) printf("%lld\n", ans);
    else puts("-1");


    return 0;
}