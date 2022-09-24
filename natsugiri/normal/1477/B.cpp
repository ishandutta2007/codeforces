#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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

int N, Q;
char buf[200011];
string S, F;

int L[200011];
int R[200011];

set<pair<int, int> > se[2];

int cnt[2];

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    F = buf;

    REP (i, Q) scanf("%d%d", L+i, R+i), L[i]--;

    se[0].clear();
    se[1].clear();

    for (int i=0; i<N;) {
	int j = i;
	while (j < N && F[i] == F[j]) j++;

	int k = F[i] - '0';
	se[k].emplace(j, i);

	i = j;
    }

    bool yes = true;

    for (int i=Q; i--;) {
	int l = L[i], r = R[i];

	REP (k, 2) {
	    cnt[k] = 0;
	    auto it = se[k].lower_bound(make_pair(l+1, -1));
	    while (it != se[k].end() && it->second < r) {
		int right = it->first;
		int left = it->second;
		se[k].erase(it++);

		if (left < l) {
		    se[k].emplace(l, left);
		    left = l;
		}
		if (r < right) {
		    se[k].emplace(right, r);
		    right = r;
		}

		cnt[k] += right - left;
	    }
	}

	if (cnt[0] == cnt[1]) {
	    yes = false;
	    break;
	}

	if (cnt[0] < cnt[1]) {
	    se[1].emplace(r, l);
	} else {
	    se[0].emplace(r, l);
	}
    }

    REP (k, 2) {
	EACH (e, se[k]) {
	    int l = e->second;
	    int r = e->first;
	    for (int i=l; i<r; i++) {
		F[i] = '0' + k;
	    }
	}
    }

    if (F != S) yes = false;

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}