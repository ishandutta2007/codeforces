#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
#include<deque>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    set<pair<int, int> > se;
    REP (i, N) se.emplace(i, A[i]);

    deque<int> qu;
    REP (i, N) qu.push_back(i);

    VI ans;

    while (!qu.empty() && se.size() >= 1) {
	int i = qu.front();
	qu.pop_front();

	auto it = se.lower_bound(make_pair(i, -1));
	if (it == se.end() || it->first != i) {
	    continue;
	}
	auto nxt = next(it);
	if (nxt == se.end()) nxt = se.begin();

	if (__gcd(it->second, nxt->second) == 1) {
	    ans.push_back(nxt->first + 1);
	    qu.push_back(it->first);
	    se.erase(nxt);
	}
    }

    printf("%d ", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}