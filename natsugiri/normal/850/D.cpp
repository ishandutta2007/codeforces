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

const int MAX = 10000;
const int INF = 0x3f3f3f3f;
const int VER = 70;
int N;
int A[33];
int dp[33][VER][MAX];
int B[VER][VER];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    REP (i, N) REP (j, VER) REP (k, MAX) if (dp[i][j][k] != INF) {
	for (int c=1; j+c<VER; c++) {
	    int cost = k + c * A[i];
	    if (cost < MAX && cost >= (j+c)*(j+c-1)/2) {
		dp[i+1][j+c][cost] = c;
	    }
	}
    }


    for (int i=1; i<VER; i++) {
	int cost = i * (i-1) / 2;
	if (cost < MAX) {
	    if (dp[N][i][cost] != INF) {
		printf("%d\n", i);
		vector<pair<int, int> > v;
		int lv = N;
		int nm = i;
		int c = cost;
		while (lv) {
		    int g = dp[lv][nm][c];
//		    eprintf("%d %d %d %d\n", lv, nm, c, g);
		    REP (z, g) {
			nm--;
			v.emplace_back(A[lv-1], nm);
		    }
		    c -= A[lv-1] * g;
		    lv--;
		}

		int n = v.size();
		REP (k, (int)v.size() - 1) {
		    sort(v.begin()+k, v.end());
		    int out = v[k].first;
		    for (int j=k+1; j<n; j++) {
			if (j <= k+out) {
			    B[v[k].second][v[j].second] = 1;
			} else {
			    B[v[j].second][v[k].second] = 1;
			    v[j].first--;
			}
		    }
		}

		REP (p, n) {
		    REP (j, n) printf("%d", B[p][j]);
		    puts("");
		}
		return;
	    }
	} else {
	    break;
	}
    }

    puts("=(");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}