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

const int MAXN = 300011;
int N;

void read(VI G[MAXN]) {
    REP (i, N) G[i].clear();
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
    }
}

VI S[MAXN];
VI K[MAXN];

int cnt = 0;
int rnk[MAXN];
int sz[MAXN];
void kdfs(int v) {
    rnk[v] = cnt++;
    sz[v] = 1;
    EACH (e, K[v]) {
	kdfs(*e);
	sz[v] += sz[*e];
    }
}

int DEL[MAXN];
bool ADD[MAXN];
map<int, int> mp;
int ans;

void sdfs(int v) {
    auto it = mp.lower_bound(rnk[v]);
    DEL[v] = -1;
    if (it != mp.end() && it->first < rnk[v] + sz[v]) {
	ADD[v] = false;
    } else {
	ADD[v] = true;
	if (it != mp.begin()) {
	    auto p = prev(it);
	    if (rnk[v] < p->first + sz[p->second]) {
		DEL[v] = p->second;
		mp.erase(p);
	    }
	}
	mp[rnk[v]] = v;
    }

    amax(ans, (int)mp.size());

    EACH (e, S[v]) {
	sdfs(*e);
    }

    if (ADD[v]) {
	mp.erase(rnk[v]);
    }
    if (DEL[v] != -1) {
	mp[rnk[DEL[v]]] = DEL[v];
    }
}


void MAIN() {
    scanf("%d", &N);
    read(S);
    read(K);

    cnt = 0;
    kdfs(0);
    ans = 1;
    sdfs(0);

    assert(mp.empty());

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}