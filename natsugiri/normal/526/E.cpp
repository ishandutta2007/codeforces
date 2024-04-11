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

int N, Q;
int A[1000011];
LL B, sum;

inline int nxt(int v) {
    int j = v; if (j>=N) j %= N;
    LL s = 0;
    for (int i=v; ; i++) {
	if (s + A[j] > B) return i;
	s += A[j];
	j++; if (j>=N) j-=N;
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) sum += A[i];
    REP ($, Q) {
	scanf("%lld", &B);
	if (B >= sum) puts("1");
	else {
	    int s = 0, v = 0, cnt = 0;
	    while (s < N) s = nxt(s);
	    v = s;
	    while (v < s+N) {
		v = nxt(v);
		cnt++;
	    }
	    printf("%d\n", cnt);
	}
    }
    return 0;
}