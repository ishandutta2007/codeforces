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

int N, M, B;
LL MOD;
int A[511];

int cur[511][511], nxt[511][511];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void test() {
    N = M = B = 500;
    memset(A, 0, sizeof A);
    MOD = 1e9 + 7;
}

int main() {
    scanf("%d%d%d%lld", &N, &M, &B, &MOD);
    REP (i, N) scanf("%d", A+i);

    cur[0][0] = 1;
    REP (i, N) {
	memset(nxt, 0, sizeof nxt);
	REP (j, B+1) REP (k, M+1) {
	    if (j+A[i]<=B && k+1 <= M) add(cur[j+A[i]][k+1], cur[j][k]);
	    add(nxt[j][k], cur[j][k]);
	}
	swap(cur, nxt);
    }
    
    int ans = 0;
    REP (j, B+1) add(ans, cur[j][M]);
    printf("%d\n", ans);
    return 0;
}