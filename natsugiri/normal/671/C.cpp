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
int A[200111];
VI G[200111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	int m = A[i];
	for (int k=1; k*k<=m; k++) {
	    if (m % k == 0) {
		G[k].push_back(i);
		if (k*k < m) G[m/k].push_back(i);
	    }
	}
    }


    LL ans = 0;
    vector<pair<int, int> > cur(N+1);
    REP (i, N+1) cur[i] = make_pair(i, i);

    for (int a=200000; a>0; a--) if (G[a].size() > 1u) {
	sort(G[a].begin(), G[a].end());
	vector<pair<int, int> > X, nxt;
	if (0 < G[a].end()[-2]) X.emplace_back(0, G[a].end()[-2]);
	if (G[a][0] < G[a].back()-1) X.emplace_back(G[a][0]+1, G[a].back());
	if (G[a][1] < N-1) X.emplace_back(G[a][1]+1, N);

	EACH (e, X) {
	    bool zero = false;
	    REP (i, cur.size()) if (e->first >= cur[i].first && e->second <= cur[i].second) {
		zero = true;
		break;
	    }

	    if (zero) continue;

	    int last = 0;
	    REP (i, cur.size()) {
		if (e->second <= last) break;

		if (cur[i].first > e->first) {
		    if (cur[i].second < e->second) {
			ans += (LL)a * (cur[i].second - last) * (cur[i].first - e->first);
		    } else {
			ans += (LL)a * (e->second - last) * (cur[i].first - e->first);
		    }
		}

		last = cur[i].second;
	    }

	    nxt.clear();
	    bool inserted = false;
	    REP (i, cur.size()) {
		if (cur[i].first < e->first) nxt.push_back(cur[i]);
		else {
		    if (!inserted) {
			nxt.push_back(*e);
			inserted = true;
		    }
		    if (cur[i].second > e->second) nxt.push_back(cur[i]);
		}
	    }
	    swap(cur, nxt);
	}

//	EACH (e, cur) eprintf("(%d %d) ", e->first, e->second); eprintf("\n");
    }

    printf("%lld\n", ans);

    return 0;
}