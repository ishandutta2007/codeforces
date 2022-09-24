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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int N, M, K;
int A[100011], P[100011];
int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) {
	scanf("%d", A+i);
	P[A[i]] = i;
    }

    LL ans = 0;
    REP (i, M) {
	int B;
	scanf("%d", &B);
	ans += P[B]/K + 1;

	if (P[B]) {
	    int x = P[B]-1, y = P[B];
	    int a = A[x], b = A[y];
	    P[b]--; P[a]++;
	    swap(A[x], A[y]);
	}
    }
    printf("%lld\n", ans);
    return 0;
}