#include<set>
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


int N;
LL S[222], D[222];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", S+i, D+i);

    set<LL> start, stop;
    stop.insert(1);
    REP (i, N) {
	LL ok = S[i];
	REP (j, i) {
	    if (S[j] < S[i] + D[i] && S[i] < S[j] + D[j]) {
		ok = -1;
		break;
	    }
	}

	if (ok == -1) {
	    EACH (e, stop) {
		set<LL>::iterator it = start.lower_bound(*e);
		if (it == start.end() || *e + D[i] <= *it) {
		    ok = *e;
		    break;
		}
	    }
	}

	S[i] = ok;
	start.insert(S[i]);
	stop.insert(S[i] + D[i]);

	printf("%lld %lld\n", S[i], S[i] + D[i] - 1);
    }
    

    return 0;
}