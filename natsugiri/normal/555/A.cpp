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

int N, K;
int A[100011];
int main() {
    scanf("%d%d", &N, &K);
    int ans = 0, cnt = 0;
    REP (i, K) {
	int m;
	scanf("%d", &m);
	REP (i, m) scanf("%d", A+i);

	if (A[0] == 1) {
	    int i = 0;
	    for ( ; i < m && A[i] == i+1; i++) ;
	    cnt += m-i + 1;
	    ans += m-i;
	} else {
	    cnt += m;
	    ans += m-1;
	}
    }
    ans += cnt-1;

    printf("%d\n", ans);
    return 0;
}