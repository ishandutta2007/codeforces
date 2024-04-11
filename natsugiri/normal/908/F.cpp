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

const LL INF = 1LL<<60;

int N;
pair<int, char> P[300111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x; char buf[9];
	scanf("%d%s", &x, buf);
	P[i].first = x;
	P[i].second = *buf;
    }

    // sort(P, P+N);
    
    LL ans = 0;
    int lastG = -1;
    int lastR = -1, lastB = -1;

    REP (i, N) {
	if (P[i].second == 'G') {
	    lastG = i;
	    break;
	} else if (P[i].second == 'R') {
	    if (lastR != -1) ans += P[i].first - P[lastR].first;
	    lastR = i;
	} else {
	    if (lastB != -1) ans += P[i].first - P[lastB].first;
	    lastB = i;
	}
    }

    if (lastG != -1) {
	if (lastR != -1) ans += P[lastG].first - P[lastR].first;
	if (lastB != -1) ans += P[lastG].first - P[lastB].first;

	vector<LL> R, B;

	for (; lastG < N; ) {
	    int j = lastG+1;
	    while (j < N && P[j].second != 'G') j++;

	    if (j == N) break;

	    R.clear();
	    B.clear();
	    R.push_back(P[lastG].first);
	    B.push_back(P[lastG].first);

	    for (int k=lastG+1; k<j; k++) {
		if (P[k].second == 'R') R.push_back(P[k].first);
		if (P[k].second == 'B') B.push_back(P[k].first);
	    }

	    R.push_back(P[j].first);
	    B.push_back(P[j].first);

	    LL r_cost = 0;
	    REP (k, (int)R.size() - 1) amax(r_cost, R[k+1] - R[k]);
	    LL b_cost = 0;
	    REP (k, (int)B.size() - 1) amax(b_cost, B[k+1] - B[k]);

	    LL cost1 = (R.back() - R[0]) * 3 - r_cost - b_cost;
	    LL cost2 = (R.back() - R[0]) * 2;
	    ans += min(cost1, cost2);

	    lastG = j;
	}

	for (int i=lastG+1; i<N; i++) {
	    if (P[i].second == 'R') lastR = i;
	    if (P[i].second == 'B') lastB = i;
	}
	if (lastG < lastR) ans += P[lastR].first - P[lastG].first;
	if (lastG < lastB) ans += P[lastB].first - P[lastG].first;
    }


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}