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

int N, M, D[100011], H[100011];
int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d", D+i, H+i);

    LL ans = 0;
    amax(ans, (LL)H[0] + (D[0] - 1));
    amax(ans, (LL)H[M-1] + (N - D[M-1]));
    REP (i, M-1) {
	if (abs(H[i+1] - H[i]) > abs(D[i+1] - D[i])) {
	    puts("IMPOSSIBLE");
	    return 0;
	}

	amax(ans, (LL)max(H[i], H[i+1]) + (abs(D[i+1] - D[i]) - abs(H[i+1] - H[i])) / 2);
    }

    printf("%lld\n", ans);
	
    return 0;
}