#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>
#include<array>

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

int ord(char c) {
    if (isupper(c)) return c - 'A';
    return c - 'a' + 26;
}
char cha(int o) {
    if (o < 26) return 'A' + o;
    return 'a' + (o - 26);
}

int N;
char buf[10000];
string S[10];
VI P[10][52];

int dp[1<<10][52];
int prv[1<<10][52];

struct Data {
    int arr[10];
    int s, c;

    Data() {
	memset(arr, 0, sizeof arr);
    }

    void clear() {
	memset(arr, 0, sizeof arr);
    }

    bool operator<(const Data &o) const {
	REP (i, 10) if (arr[i] != o.arr[i]) {
	    return arr[i] < o.arr[i];
	}
	return false;
    }
};

vector<Data> G;


void MAIN() {
    scanf("%d", &N);

    REP (i, N) {
	scanf("%s", buf);
	S[i] = buf;
    }

#ifdef LOCAL
    N = 10;
    REP (i, N) {
	S[i].clear();
	REP (j, 52) {
	    S[i].push_back(cha(j));
	    S[i].push_back(cha(j));
	}
	random_shuffle(S[i].begin(), S[i].end());
    }
#endif

    REP (i, N) REP (c, 52) P[i][c].clear();

    REP (i, N) {
	REP (j, S[i].size()) P[i][ord(S[i][j])].push_back(j);
    }

    G.clear();

    REP (c, 52) {
	REP (s, 1<<N) {
	    bool yes = true;
	    Data d = Data();
	    REP (i, N) {
		if (P[i][c].empty()) { yes = false; break; }
		if ((s>>i&1) && P[i][c].size() <= 1u) { yes = false; break; }
		d.arr[i] = P[i][c][s>>i&1];
	    }
	    if (yes) {
		d.s = s;
		d.c = c;
		G.push_back(d);
	    }
	}
    }

    memset(dp, 0, sizeof dp);

    sort(G.begin(), G.end());

    REP (i, G.size()) {
	int s = G[i].s;
	int c = G[i].c;

	if (dp[s][c] == 0) {
	    prv[s][c] = -1;
	    dp[s][c] = 1;
	}

	REP (nxt, 52) {
	    bool yes = true;
	    int nxt_s = 0;

	    REP (k, N) {
		if (P[k][nxt].empty()) {
		    yes = false;
		    break;
		} else if (G[i].arr[k] >= P[k][nxt].back()) {
		    yes = false;
		    break;
		} else {
		    REP (t, P[k][nxt].size()) {
			if (G[i].arr[k] < P[k][nxt][t]) {
			    nxt_s |= t << k;
			    break;
			}
		    }
		}
	    }

	    if (yes) {
		if (dp[nxt_s][nxt] < dp[s][c] + 1) {
		    dp[nxt_s][nxt] = dp[s][c] + 1;
		    prv[nxt_s][nxt] = s * 52 + c;
		}
	    }
	}
    }


    int bests = 0, bestc = 0;
    int len = -1;
    REP (s, 1<<N) REP (c, 52) if (dp[s][c] > len) {
	len = dp[s][c];
	bests = s;
	bestc = c;
    }
    printf("%d\n", len);

    string ans;
    if (len) {
	while (1) {
	    ans.push_back(cha(bestc));
	    if (dp[bests][bestc] == 1) break;
	    int nxts = prv[bests][bestc] / 52;
	    int nxtc = prv[bests][bestc] % 52;
	    bests = nxts;
	    bestc = nxtc;
	}
    }
    reverse(ans.begin(), ans.end());
    puts(ans.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}