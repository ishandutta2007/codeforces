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

int N;
int M;

int C[3001111];
LL D[3001111];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	C[x]++;
    }

    REP (i, 3000111) if (C[i]) {
	int s = 0;
	int j = 0;
	for (; j * i < 3000111; j++) {
	    if (i == j) {
		D[i * j] += (LL)(C[j] - 1) * C[i];
		s += C[j] - 1;
	    } else {
		D[i * j] += (LL)C[j] * C[i];
		s += C[j];
	    }
	}
	D[3000111] += (LL)(N - 1 - s) * C[i];
    }

    for (int i=3000111; i>=0; i--) D[i] += D[i+1];

    scanf("%d", &M);
    REP (i, M) {
	int x ;
	scanf("%d", &x);
	printf("%lld\n", D[x]);
    }


    return 0;
}