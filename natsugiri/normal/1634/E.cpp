#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int M;
VI A[100011];
string S[100011];

map<int, vector<pair<int, int> > > mp;
int iter[100011];

void MAIN() {
    scanf("%d", &M);
    REP (i, M) {
	int len;
	scanf("%d", &len);
	A[i].reserve(len);
	S[i].assign(len, '?');

	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    A[i].push_back(x);
	    // (x, i, j);
	    mp[x].emplace_back(i, j);
	}
    }

    bool yes = true;

    REP (i, M) {
	if (!yes) break;

	while (yes && iter[i] < (int)A[i].size()) {
	    int j = iter[i]++;

	    if (S[i][j] != '?') continue;

	    int cx = A[i][j];
	    int ci = i;
	    int cj = j;

	    while (1) {
		vector<pair<int, int> > &stk = mp[cx];
		int ni = -1;
		int nj = -1;

		while (!stk.empty()) {
		    ni = stk.back().first;
		    nj = stk.back().second;
		    stk.pop_back();

		    if (ni == ci && nj == cj) {
			ni = nj = -1;
		    } else if (S[ni][nj] == '?') {
			break;
		    } else {
			ni = nj = -1;
		    }
		}

		if (ni == -1) {
		    yes = false;
		    break;
		}

		S[ci][cj] = 'L';
		S[ni][nj] = 'R';

		if (ni == i) {
		    break;
		}

		ci = ni;
		cj = -1;
		ni = nj = -1;

		while (iter[ci] < (int)A[ci].size()) {
		    cj = iter[ci]++;
		    if (S[ci][cj] != '?') continue;

		    cx = A[ci][cj];
		    break;
		}

		if (cj == -1) {
		    yes = false;
		    break;
		}
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, M) puts(S[i].c_str());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}