#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
#include<map>

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

int N, M;
int A[200011];

VI ADD[200011];
int DEL[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	ADD[i].clear();
	DEL[i] = 0;
    }

    REP (i, M) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	ADD[l].push_back(r);
	DEL[r]++;
    }

    map<int, VI> mp;
    for (int i=N; i--;) {
	mp[A[i]].push_back(i);
    }

    multiset<int> se;
    vector<pair<int, int> > P;

    int left = N;
    int right = -1;
    REP (i, N) {
	VI &v = mp[A[i]];
	assert(v.back() == i);
	if (DEL[i]) {
	    auto it = se.lower_bound(i);
	    REP (t, DEL[i]) {
		se.erase(it++);
	    }
	}

	EACH (e, ADD[i]) {
	    se.insert(*e);
	}

	if (se.size() && v.size() >= 2u) {
	    int r = *se.rbegin();
	    int k = lower_bound(v.rbegin(), v.rend(), r) - v.rbegin();
	    if (k >= 2) {
		// v.rbegin()[0] == i;
		// v.rbegin()[k] >= r;
		if (k >= 3) {
		    amin(left, v.rbegin()[1]);
		    amax(right, v.rbegin()[k-2] + 1);
		}
		P.emplace_back(v.rbegin()[0], v.rbegin()[k-1]);
	    }
	}

	v.pop_back();
    }

    if (right != -1) {
	vector<pair<int, int> > Q;
	sort(P.begin(), P.end());
	EACH (e, P) {
	    if (left <= e->first && e->first < right) {
		
	    } else if (right <= e->first) {
		amax(right, e->first + 1);
	    } else {
		Q.push_back(*e);
	    }
	}
	swap(P, Q);

	sort(P.begin(), P.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
		});
	Q.clear();
	EACH (e, P) {
	    if (left <= e->second && e->second < right) {
		
	    } else if (e->second < left) {
		amin(left, e->second);
	    } else {
		Q.push_back(*e);
	    }
	}
	swap(P, Q);
    }

    int ans = 0;
    if (right == -1 && P.empty()) {
	ans = 0;
    } else if (P.empty()) {
	ans = right - left;
    } else {
	ans = N;

	REP (i, N) ADD[i].clear();
	se.clear();

	EACH (e, P) {
	    se.insert(e->first);
	    ADD[e->first].push_back(e->second);
	}

	amin(ans, max(right, *se.rbegin() + 1)  - min(left, *se.begin()));
	REP (i, N) {
	    auto it = se.lower_bound(i);
	    EACH (e, ADD[i]) {
		se.erase(it++);
		se.insert(*e);
	    }
	    amin(ans, max(right, *se.rbegin() + 1)  - min(left, *se.begin()));
	}
    }

    printf("%d\n", ans);
    // eprintf("------------\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}