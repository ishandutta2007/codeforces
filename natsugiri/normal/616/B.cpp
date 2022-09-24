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

int N, M, A[111];
int ans;
int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int tmp = 1e9, x;
	REP (j, M) {
	    scanf("%d", &x);
	    amin(tmp, x);
	}
	amax(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}