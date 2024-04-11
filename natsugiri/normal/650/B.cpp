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


int N, A, B, T;
char S[500111];
LL sums[500111];

int calc() {
    int ans = 0;

    REP (i, N-1) {
	sums[i+1] = sums[i] + A + (S[i+1] == 'w'? B: 0) + 1;
    }
    sums[N] = 1LL<<60;

    LL c = 0;
    REP (i, N) {
	c++;
	if (S[(N-i)%N] == 'w') c += B;
	if (c > T) break;

	amax(ans, i+1);
	int k = upper_bound(sums, sums + N-i, T - c - (LL)A * i) - sums;

	if (k >= 1) amax(ans, i+k);

	c += A;
    }
    return ans;
}

int main() {
    scanf("%d%d%d%d%s", &N, &A, &B, &T, S);

    int ans = calc();
    reverse(S+1, S+N);
    amax(ans, calc());
    
    printf("%d\n", ans);


    return 0;
}