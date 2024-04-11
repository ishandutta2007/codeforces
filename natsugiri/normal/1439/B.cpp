#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

const int MAGIC = 345;

int N, M, K;
VI G[100011];

int C[100011];

int deg[100011];
bool use[100011];
VI h;
VI stk;
VI ans;


void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) G[i].clear();

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) sort(G[i].begin(), G[i].end());

    stk.clear();

    REP (i, N) {
	deg[i] = G[i].size();
	use[i] = false;
	if (deg[i] < K-1) {
	    use[i] = true;
	    stk.push_back(i);
	}
    }

    while (!stk.empty()) {
	int v = stk.back();
	stk.pop_back();
	deg[v] = -1;

	EACH (e, G[v]) {
	    deg[*e]--;
	    if (!use[*e] && deg[*e] < K-1) {
		use[*e] = true;
		stk.push_back(*e);
	    }
	}
    }

    REP (i, N) if (!use[i] && deg[i] == K-1) {
	use[i] = true;
	stk.push_back(i);
    }

    while (!stk.empty()) {
	int v = stk.back();
	stk.pop_back();

	if (deg[v] == K-1) { // clique?;
	    h.clear();
	    EACH (e, G[v]) {
		if (deg[*e] >= K-1) {
		    h.push_back(*e);
		}
	    }
	    if ((int)h.size() == K-1) {

		bool clique = true;
		h.push_back(v);

		if (K >= MAGIC) {
		    // (N/MAGIC) * M;
		    EACH (e, h) C[*e] = 0;

		    EACH (e, h) {
			for (int i=0; i<(int)G[*e].size(); i++) {
			    int w = G[*e][i];
			    if (deg[w] >= K-1) {
				C[w]++;
			    }
			}
		    }

		    EACH (e, h) if (C[*e] != K-1) {
			clique = false;
			break;
		    }
		} else {
		    // (N/MAGIC) * MAGIC^2 * log(N)
		    sort(h.begin(), h.end());
		    EACH (e, h) {
			auto head = G[*e].begin();

			EACH (f, h) {
			    if (*f == *e) continue;
			    auto it = lower_bound(head, G[*e].end(), *f);
			    if (it != G[*e].end() && *it == *f) {
				head = next(it);
			    } else {
				clique = false;
				goto OUT;
			    }
			}
		    }

OUT:
		    ;
		}

		if (clique) {
		    puts("2");
		    REP (i, h.size()) {
			printf("%d%c", h[i]+1, " \n"[i==(int)h.size()-1]);
		    }
		    return;
		}
	    }
	}

	deg[v] = -1;

	EACH (e, G[v]) {
	    deg[*e]--;
	    if (!use[*e] && deg[*e] == K-1) {
		use[*e] = true;
		stk.push_back(*e);
	    }
	}
    }

    ans.clear();
    REP (i, N) if (!use[i]) ans.push_back(i+1);

    if (ans.empty()) {
	puts("-1");
    } else {
	printf("1 %d\n", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}