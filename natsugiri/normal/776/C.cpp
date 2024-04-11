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

int N, K;
int A[100111];
LL sums[100111];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    LL ans = 0;
    LL p = 1;
    vector<LL> ps;
    for (;;) {
	ps.push_back(p);


	if (abs(p) >= (LL)(1e15)) break;
	if (K == 1) break;
	if (K == -1 && p == -1) break;
	p *= K;
    }

    map<LL, int> mp;
    mp[0] = 1;
    LL cur = 0;
    REP (i, N) {
	cur += A[i];

	EACH (e, ps) {
	    p = *e;
	    auto it = mp.find(cur - p);
	    if (it != mp.end()) ans += it->second;
	}

	mp[cur]++;
    }


    printf("%lld\n", ans);

    return 0;
}