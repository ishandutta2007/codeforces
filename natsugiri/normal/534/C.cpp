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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, D[200111];
LL A, sum;

int main() {
    scanf("%d%lld", &N, &A);
    REP (i, N) scanf("%d", D+i);
    REP (i, N) sum += D[i];

    REP (i, N) {
	LL ans = min(1-N+A, (LL)D[i]) - max(D[i]-sum+A-1, 0LL);
	amax(ans, 0LL);
	printf("%d%c", (int)(D[i]-ans), i+1 == N? '\n': ' ');
    }
    return 0;
}