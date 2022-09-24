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

int N, K;
double P[21];
double A[1<<20], B[1<<20];

double C[21];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lf", P+i);


    int cnt = 0;
    REP (i, N) if (P[i] != 0) cnt++;

    if (cnt <= K) {
	REP (i, N) C[i] = (P[i] == 0? 0: 1);
    } else {
	REP (r, N) {

	    if (P[r] == 0) {
		C[r] = 0;
	    } else {
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);

		for (int s=(1<<N)-1; s >= (1<<r); s--) {
		    if (__builtin_popcount(s) > K) {

		    } else {
			double t = 0;
			for (int i=0; i<N; i++) {
			    if (i == r) {
				A[s] += P[i];
			    } else if (s & (1<<i)) {
				t += P[i];
			    } else {
				A[s] += P[i] * A[s | (1<<i)];
				B[s] += P[i] * B[s | (1<<i)];
			    }
			}

			B[s] += 1;
			A[s] /= 1 - t;
			B[s] /= 1 - t;
		    }
		}

		double e = B[1<<r] / (1 - A[1<<r]);
//		eprintf("%f %f %f\n", A[1<<r], B[1<<r], e);

		C[r] = e / (e + (1.0 / P[r]));
	    }
	}
    }

    REP (i, N) printf("%.9f%c", C[i], i==N-1?'\n':' ');


    return 0;
}