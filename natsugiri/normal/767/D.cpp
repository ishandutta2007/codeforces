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

const int MAXN = 1000011;
int N, M, K;
int F[MAXN], S[MAXN];
pair<int, int> P[MAXN];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", F+i);
    REP (i, M) scanf("%d", &P[i].first), P[i].second = i;
    sort(F, F+N);
    sort(P, P+M);
    bool yes = true;
    REP (i, N) if (F[i] < i/K) yes = false;

    F[N] = -1;
    P[M] = make_pair(-1, -1);
    VI ans;

    if (yes) {
	int i = 0, j = 0;
	int last = 0;
	while (i < N || j < M) {
	    if (last/K == F[i]) {
		i++;
		last++;
	    } else {
		while (j < M && P[j].first < last/K) j++;
		if (last/K <= F[i] && last/K <= P[j].first) {
		    if (P[j].first < F[i]) {
			ans.push_back(P[j].second);
			j++;
			last++;
		    } else {
			i++;
			last++;
		    }
		} else if (last/K <= P[j].first) {
		    ans.push_back(P[j].second);
		    j++;
		    last++;
		} else if (last/K <= F[i]) {
		    i++;
		    last++;
		} else {
		    break;
		}
	    }
	}
	EACH (e, ans) ++*e;
	printf("%d\n", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
//	eprintf("%d\n", last);
    } else {
	puts("-1");
    }

    return 0;
}