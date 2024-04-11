#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

typedef vector<VI> Adj;
int N, M;
Adj G;

const int MAX = 100011;
int col[MAX], cc[MAX];
bool use[MAX];
bool dfs(int v) {
    EACH (e, G[v]) {
	if (col[*e] == 0) {
	    col[*e] = 3 - col[v];
	    cc[*e] = cc[v];
	    if (!dfs(*e)) return false;
	} else if (col[*e] != 3 - col[v]) {
	    return false;
	}
    }
    return true;
}

bool two_coloring() {
    memset(cc, -1, sizeof cc);
    REP (i, N) if (col[i] == 0) {
	col[i] = 1;
	cc[i] = i;
	if (!dfs(i)) return false;
    }
    return true;
}

bool has_v() {
    REP (i, N) if (G[i].size() > 1u) return true;
    return false;
}

int tbl[2][MAX];
LL solve() {
    REP (i, N) {
	tbl[col[i]-1][cc[i]]++;
    }
    LL ans = 0;
    REP (j, 2) REP (i, N) {
	LL t = tbl[j][i];
	ans += t * (t-1) / 2;
    }
    return ans;
}

int main() {
    scanf("%d%d", &N, &M);
    G.resize(N);
    REP (i, M) {
	int a,b ;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    if (!two_coloring()) {
	puts("0 1");
    } else if (has_v()) {
	LL ans = solve();
	printf("1 %lld\n", ans);
    } else if (M) {
	printf("2 %lld\n", (LL)M * (N-2));
    } else {
	printf("3 %lld\n", (LL)N*(N-1)*(N-2)/6);
    }
    return 0;
}