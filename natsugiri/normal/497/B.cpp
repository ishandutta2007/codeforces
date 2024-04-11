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
int A[100111];
int sums[2][100111];
vector<pair<int, int> > ans;

void calc(const int T) {
    int sets[2] = {};
    int last = -1;
    int cur = 0;
    while (cur < N) {
	int l = cur, r = N+1;
	while (r - l > 1) {
	    int m = (r + l) / 2;
	    if (sums[0][m] - sums[0][cur] >= T ||
		    sums[1][m] - sums[1][cur] >= T)
		r = m;
	    else l = m;
	}

	if (r == N+1) return;

	if (sums[0][r] - sums[0][cur] >= T) { sets[0]++; last = 0; }
	else { sets[1]++; last = 1; }
	cur = r;
    }

    if (last != -1 && sets[last] > sets[1 - last]) {
	ans.emplace_back(make_pair(max(sets[0], sets[1]), T));
    }
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, N) {
	sums[0][i+1] = sums[0][i];
	sums[1][i+1] = sums[1][i];
	sums[A[i]][i+1]++;
    }

    for (int d=1; d<=N; d++) calc(d);

    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}