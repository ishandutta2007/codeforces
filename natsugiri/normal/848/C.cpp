#include<cassert>
#include<set>
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

const int MAXN = 100011;
const int MAGIC = 333;
const int NUMB = MAXN / MAGIC + 11;

struct Block {
    int n;
    // (prev, own);
    pair<int, int> p[MAGIC];
    LL sums[MAGIC+1];

    void init() {
	sort(p, p+n);
	sums[0] = 0;
	REP (i, n) {
	    sums[i+1] = sums[i] + p[i].second - p[i].first;
	}
    }

    void rewrite(int fst, int snd) {
	REP (i, n) {
	    if (p[i].second == snd) {
		p[i].first = fst;
		return;
	    }
	}
	assert(false);
    }

    LL solve(int l, int r) const {
	LL ret = 0;
	REP (i, n) {
	    if (l <= p[i].first && p[i].second <= r) ret += p[i].second - p[i].first;
	}
	return ret;
    }

    LL quick(int l) const {
	int k = lower_bound(p, p+n, make_pair(l, -1)) - p;
	return sums[n] - sums[k];
    }
} B[NUMB];

int N, M;
int A[MAXN];

set<int> S[MAXN];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);

    for (int L=0, i=0; L<N; L+=MAGIC, i++) {
	int R = min(N-1, L+MAGIC-1);
	B[i].n = R-L+1;
	for (int j=L; j<=R; j++) {
	    int a = A[j];
	    B[i].p[j-L].first = (S[a].empty()? -1: *S[a].rbegin());
	    B[i].p[j-L].second = j;
	    S[a].insert(S[a].end(), j);
	}

	B[i].init();
    }

    REP ($, M) {
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    int p, x;
	    scanf("%d%d", &p, &x);
	    p--;
	    
	    int a = A[p];
	    if (a == x) continue;

	    VI update_blocks;

	    {
		auto it = S[a].lower_bound(p);
		S[a].erase(it++);
		if (it != S[a].end()) {
		    int right = *it;
		    int id = right / MAGIC;
		    update_blocks.push_back(id);
		    if (it == S[a].begin()) {
//			pre[right] = -1;
			B[id].rewrite(-1, right);
		    } else {
			--it; // left
			//pre[right] = *it;
			B[id].rewrite(*it, right);
		    }
		}
	    }

	    {
		auto it = S[x].upper_bound(p);
		if (it != S[x].end()) {
		    int right = *it;
		    int id = right / MAGIC;
		    update_blocks.push_back(id);
		    // pre[right] = p;
		    B[id].rewrite(p, right);
		}

		int my_id = p / MAGIC;
		update_blocks.push_back(my_id);
		if (it == S[x].begin()) {
		    // pre[p] = -1;
		    B[my_id].rewrite(-1, p);
		} else {
		    --it;
		    // pre[p] = *it;
		    B[my_id].rewrite(*it, p);
		    ++it;
		}
		S[x].insert(it, p);
	    }

	    A[p] = x;

	    sort(update_blocks.begin(), update_blocks.end());
	    update_blocks.erase(unique(update_blocks.begin(), update_blocks.end()), update_blocks.end());
	    EACH (e, update_blocks) B[*e].init();
	} else {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    l--; r--;
	    
	    int l_id = l / MAGIC;
	    int r_id = r / MAGIC;
	    LL ans = 0;

	    if (l_id == r_id) {
		ans += B[l_id].solve(l, r);
	    } else {
		ans += B[l_id].solve(l, r);
		for (int i=l_id+1; i<r_id; i++) ans += B[i].quick(l);
		ans += B[r_id].solve(l, r);
	    }

	    printf("%lld\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}