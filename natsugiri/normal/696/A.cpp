#include<map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100111];
map<LL, LL> mp;

int main() {
    scanf("%d", &N);
    REP (i, N) {
	LL op, x, y, w;
	scanf("%lld%lld%lld", &op, &x, &y);
	if (op == 1) {
	    scanf("%lld", &w);
	    while (x != y) {
		if (x < y) swap(x, y);
		mp[x] += w;
		x >>= 1;
	    }
	} else {
	    LL ans = 0;
	    while (x != y) {
		if (x < y) swap(x, y);
		map<LL, LL>::iterator it = mp.find(x);
		if (it != mp.end()) ans += it->second;
		x >>= 1;
	    }

	    printf("%lld\n", ans);
	}
    }


    return 0;
}