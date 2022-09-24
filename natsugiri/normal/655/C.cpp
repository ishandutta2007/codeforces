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
char S[100111];
int sums[100111];

int main() {

    scanf("%d%d%s", &N, &K, S);

    REP (i, N) {
	sums[i+1] += sums[i];
	if (S[i] == '0') sums[i+1]++;
    }

    int ans = N;
    REP (i, N) if (S[i] == '0') {
	int lo = 0, hi = N;
	while (hi - lo > 1) {
	    int m = (lo + hi) / 2;
	    if (sums[min(N, i+m+1)] - sums[max(0, i-m)] >= K + 1) hi = m;
	    else lo = m;
	}
	amin(ans, hi);
    }

    printf("%d\n", ans);


    return 0;
}