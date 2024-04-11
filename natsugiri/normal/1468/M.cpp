#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N;
VI As;
VI G[100011];
VI H[200011];

const int MAGIC = 340;
int Table[611][100011];

void MAIN() {
    scanf("%d", &N);
    As.clear();
    REP (i, N) {
	int len;
	scanf("%d", &len);
	G[i].resize(len);
	REP (j, len) scanf("%d", &G[i][j]);
	As.insert(As.end(), G[i].begin(), G[i].end());
    }

    sort_unique(As);

    REP (i, As.size()+1u) H[i].clear();

    REP (i, N) {
	REP (j, G[i].size()) {
	    G[i][j] = lower_bound(As.begin(), As.end(), G[i][j]) - As.begin();
	}
    }

    REP (i, N) {
	REP (j, G[i].size()) {
	    H[G[i][j]].push_back(i);
	}
    }

    map<int, int> mp;
    REP (i, As.size()) if (H[i].size() >= MAGIC) {
	int idx = mp.size();
	mp.emplace(i, idx);
	EACH (f, H[i]) Table[idx][*f]++;
    }

    pair<int, int> ans(-1, -1);
    REP (i, N) {
	int ma = As.size();
	EACH (e, G[i]) {
	    if (H[*e].size() >= MAGIC && H[ma].size() < H[*e].size()) {
		ma = *e;
	    }
	}

	auto it = mp.find(ma);
	int idx = (it == mp.end()? mp.size(): it->second);

	EACH (e, G[i]) if (*e != ma) {
	    EACH (f, H[*e]) if (*f != i) {
		Table[idx][*f]++;
		if (ans.first == -1 && Table[idx][*f] >= 2) {
		    ans = make_pair(i, *f);
		}
	    }
	}

	EACH (e, G[i]) if (*e != ma) {
	    EACH (f, H[*e]) if (*f != i) {
		Table[idx][*f]--;
	    }
	}

	if (ans.first != -1) break;
    }

    if (ans.first == -1) {
	puts("-1");
    } else {
	printf("%d %d\n", ans.first+1, ans.second+1);
    }

    EACH (e, mp) {
	int i = e->first;
	int idx = e->second;
	EACH (f, H[i]) Table[idx][*f]--;
	//rprintf("%d", Table[idx], Table[idx] + 10);
	// assert(0 == *max_element(Table[idx], Table[idx]+100000));
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}