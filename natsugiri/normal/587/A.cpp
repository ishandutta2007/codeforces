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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, A[2000011], W;
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &W);
	A[W]++;
    }

    int ans = 0;
    REP (i, 2000000) {
	if (A[i] > 1) {
	    A[i+1] += A[i] / 2;
	    A[i] %= 2;
	}
	ans += A[i];
    }

    printf("%d\n", ans);
    return 0;
}