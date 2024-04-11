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


int main() {
    LL N;
    scanf("%lld", &N);

    int ans = 0;
    N %= 360;
    if (N < 0) N += 360;

    LL best = 33333;
    REP (i, 4) {
	LL g = N-i*90;
	g %= 360;
	if (g < 0) g += 360;
	if (g < best) {
	    best = g;
	    ans = i;
	}
	if (360 - g < best) {
	    best = 360 - g;
	    ans = i;
	}
    }
    
    printf("%d\n", ans);
    return 0;
}