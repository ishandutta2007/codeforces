#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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

int Q;
bool use[500011];
int idx, cnt;
priority_queue<pair<int, int> > pq;
VI ans;

void MAIN() {
    scanf("%d", &Q);

    REP ($, Q) {
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    int m;
	    scanf("%d", &m);
	    pq.emplace(m, -cnt);
	    cnt++;
	} else if (op == 2) {
	    while (use[idx]) idx++;
	    ans.push_back(idx+1);
	    use[idx] = true;
	} else if (op == 3) {
	    int k = -1;
	    while (1) {
		k = -pq.top().second;
		pq.pop();
		if (!use[k]) break;
	    }
	    use[k] = true;
	    ans.push_back(k+1);
	}
    }

    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}