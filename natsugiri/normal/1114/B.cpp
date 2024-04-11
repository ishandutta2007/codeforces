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

int N, M, K;
pair<int, int> P[200011];
int A[200011];
bool B[200011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	P[i] = make_pair(x, i);
    }

    sort(P, P+N);
    reverse(P, P+N);
    REP (i, K*M) {
	A[P[i].second] = P[i].first;
	B[P[i].second] = true;
    }

    LL sum = 0;
    VI ans;
    for (int i=0, cnt=0; cnt<K; cnt++) {
	int j = i;
	int t = 0;
	while (t < M) {
	    sum += A[j];
	    if (B[j]) t++;
	    j++;
	}
	if (cnt == K-1) {
	    j = N;
	} else {
	    ans.push_back(j);
	}
	
	i = j;
    }
    printf("%lld\n", sum);
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}