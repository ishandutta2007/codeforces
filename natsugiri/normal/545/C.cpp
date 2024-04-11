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

int N;
LL X[100011], H[100011];


int main() {

    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, H+i);

    LL left = -(1LL<<60);
    int ans = 0;
    REP (i, N) {
	LL le = X[i] - H[i], ri = X[i] + H[i];
	if (left < le) {
	    ans++;
	    amax(left, X[i]);
	} else {
	    if (i == N-1 || ri < X[i+1]) {
		ans++;
		amax(left, ri);
	    } else {
		amax(left, X[i]);
	    }
	}
    }
    printf("%d\n", ans);

    return 0;
}