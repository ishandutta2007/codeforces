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
int A[5011];
int key[100111], val[100111];

int dp1[5011][5011]; // (key, key)
int dp2[7][5011]; // (7, key);
int dp3[5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    memset(key, -1, sizeof key);

    int cnt = 0;
    REP (i, N) if (key[A[i]] == -1) {
	val[cnt] = A[i];
	key[A[i]] = cnt++;
    }

    memset(dp1, 0xc0, sizeof dp1);
    memset(dp2, 0xc0, sizeof dp2);
    memset(dp3, 0xc0, sizeof dp3);


    vector<pair<int, int> > update;
    REP (i, N) {
	int k = key[A[i]];
	update.clear();

	int x[2];
	x[0] = key[A[i]-1];
	x[1] = key[A[i]+1];
	int s = A[i] % 7;
    
	REP (j, 2) {
	    if (x[j] != -1) {
		REP (t, cnt) {
		    if (dp1[x[j]][t] >= 0) {
			update.emplace_back(t, dp1[x[j]][t] + 1);
		    }
		}

		if (dp3[x[j]] >= 0) {
		    update.emplace_back(-1, dp3[x[j]] + 1);
		}
	    }
	}

	REP (t, cnt) {
	    if (dp2[s][t] >= 0) {
		update.emplace_back(t, dp2[s][t] + 1);
	    }

	    if (s == val[t] % 7) {
		if (dp3[t] >= 0) {
		    update.emplace_back(-1, dp3[t] + 1);
		}
	    }

	    if (dp3[t] >= 0) {
		update.emplace_back(t, dp3[t] + 1);
	    }
	}

	EACH (e, update) {
	    int t = e->first, w = e->second;
	    if (t == -1) {
		amax(dp3[k], w);
	    } else {
		amax(dp1[k][t], w);
		amax(dp1[t][k], w);
		amax(dp2[s][t], w);
		amax(dp2[val[t]%7][k], w);
	    }
	}
	amax(dp3[k], 1);

    }

    int ans = 0;
    REP (i, cnt) REP (j, cnt) amax(ans, dp1[i][j]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}