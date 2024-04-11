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

LL lcm(LL x, LL y) {
    return x / __gcd(x, y) * y;
}

int N, R[30], M[30];
bool X[1000111];
int L, C;

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", M+i);
    REP (i, N) scanf("%d", R+i);
    L = 1;
    REP (i, N) L = lcm(M[i], L);


    REP (i, N) {
	int c = R[i];
	while (c < L) {
	    X[c] = true;
	    c += M[i];
	}
    }

    REP (i, L) if (X[i]) C++;


    printf("%.9f\n", (double) C / L);


    return 0;
}