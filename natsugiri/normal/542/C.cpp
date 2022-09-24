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

LL lcm(LL x, LL y) { return x / __gcd<LL>(x, y) * y; }

int N, A[222], C[222];

int main() {
    scanf("%d", &N);
    REP (i, N) { scanf("%d", A+i); A[i]--; }

    LL m = 1;
    vector<LL> X;
    REP (i, N) {
	memset(C, -1, sizeof C);
	for (int j=i, cnt=0; ; cnt++) {
	    if (C[j] != -1) {
		if (j == i) X.push_back(cnt);
		else amax(m, (LL)C[j]);
		break;
	    }
	    C[j] = cnt;
	    j = A[j];
	}
    }

    LL ans;
    LL l = 1;
    EACH (e, X) l = lcm(l, *e);
    ans = l;
    while (ans < m) ans += l;
    printf("%lld\n", ans);
    
    return 0;
}