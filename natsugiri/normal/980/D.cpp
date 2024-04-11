#include<set>
#include<map>
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
int ans[5011];
map<int, int> mp;
bool use[5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
//    N = 5000;
//    REP (i, N) A[i] = rand() % 100000000;

    REP (i, N) {
	if (A[i] == 0) {

	} else {
	    int t = abs(A[i]);
	    int m = 1;
	    for (int p=2; p*p<=t; p++) {
		int cnt = 0;
		while (t % p == 0) {
		    t /= p;
		    cnt++;
		}
		if (cnt & 1) m *= p;
	    }
	    if (t > 1) m *= t;

	    if (A[i] < 0) m = -m;
	    auto it = mp.lower_bound(m);
	    if (it == mp.end() || it->first != m) {
		int tmp = mp.size()+1;
		mp.insert(it, make_pair(m, tmp));
		A[i] = tmp;
	    } else {
		A[i] = it->second;
	    }
	}
    }

    REP (s, N) {
	int zero = 0;
	int cnt = 0;
	for (int i=s; i<N; i++) {
	    if (A[i] == 0) zero++;
	    else if (!use[A[i]]) { cnt++; use[A[i]] = true; }

	    if (zero && cnt==0) ans[1]++;
	    else ans[cnt]++;
	}
	for (int i=s; i<N; i++) {
	    use[A[i]] = false;
	}
    }
    rprintf("%d", ans+1, ans+N+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}