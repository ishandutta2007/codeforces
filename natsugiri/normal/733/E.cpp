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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct Sums {
    vector<LL> d;
    Sums(const VI &v) : d(v.size()+1) {
	REP (i, v.size()) d[i+1] = d[i] + v[i];
    }
    LL sum(int i) { return d[i]; }
    LL sum(int i, int j) { return d[j] - d[i]; }
    int lower_bound(LL k) {
	int l = -1, h = d.size();
	while (h - l > 1) {
	    int m = (h + l) / 2;
	    if (d[m] >= k) h = m;
	    else l = m;
	}
	return h-1;
    }
};

int N, A[1000111];
char S[1000111];

int main() {
    scanf("%d%s", &N, S);

    REP (i, N) A[i] = (S[i] == 'U');
    Sums L(VI(A, A+N+1));
    REP (i, N) A[i] = (S[i] == 'D');
    Sums R(VI(A, A+N+1));
    REP (i, N) A[i] = (S[i] == 'U'? i : 0);
    Sums Lx(VI(A, A+N+1));
    REP (i, N) A[i] = (S[i] == 'D'? i : 0);
    Sums Rx(VI(A, A+N+1));


    REP (i, N) {
	LL ans = 0;

	if (S[i] == 'U' && L.sum(i+1) <= R.sum(i+1, N)) {
	    int k = L.sum(i+1) + R.sum(i+1);
	    int pos = R.lower_bound(k);
	    ans += 2LL * (Rx.sum(i+1, pos+1) - Lx.sum(i+1)) + i + 1;
	} else if (S[i] == 'U') {
	    int t = L.sum(i+1);
	    int k = R.sum(i+1, N);
	    int pos = L.lower_bound(t - k);
	    ans += 2LL * (Rx.sum(i+1, N) - Lx.sum(pos, i+1)) + i + N;
	} else if (S[i] == 'D' && L.sum(i) >= R.sum(i, N)) {
	    int t = L.sum(i);
	    int k = R.sum(i, N);
	    int pos = L.lower_bound(t - k + 1);
	    ans += 2LL * (Rx.sum(i, N) - Lx.sum(pos, i)) - i + N;
	} else if (S[i] == 'D') {
	    int k = L.sum(i) + R.sum(i+1);
	    int pos = R.lower_bound(k);
	    ans += 2LL * (Rx.sum(i, pos+1) - Lx.sum(i)) - i + 1;
	}

	printf("%lld%c", ans, i==N-1? '\n': ' ');
    }


    return 0;
}