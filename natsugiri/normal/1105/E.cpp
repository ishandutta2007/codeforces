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

typedef unsigned long long ULL;

vector<ULL> all_independent_sets(ULL adj[], int n) {
    vector<ULL> ret;
    ret.push_back(0);
    REP (i, n) {
	int len = ret.size();
	for (int j=0; j<len; j++) {
	    if ((ret[j] & adj[i]) == 0) ret.push_back(ret[j] | (1ULL<<i));
	}
    }
    return ret;
}

ULL indipendent_set(ULL adj[], int n) {
    if (n <= 20) {
	vector<ULL> v = all_independent_sets(adj, n);
	ULL ans = 0;
	EACH (e, v) if (__builtin_popcount(ans) < __builtin_popcount(*e)) ans = *e;
	return ans;
    } else if (n <= 40) {
	vector<ULL> left(n/2), right(n-n/2);
	ULL mask = (1LL<<(n/2))-1;
	REP (i, n/2) left[i] = adj[i] & mask;
	REP (i, n-n/2) right[i] = adj[i+n/2] >> (n/2);

	vector<ULL> left_sets = all_independent_sets(left.data(), n/2);
	vector<ULL> right_sets = all_independent_sets(right.data(), n-n/2);

	vector<ULL> dp(1<<(n/2));
	EACH (e, left_sets) dp[*e] = *e;
	REP (s, 1<<(n/2)) if (dp[s] == 0) {
	    REP (i, n/2) if (s>>i&1) {
		int t = s ^ (1<<i);
		if (__builtin_popcount(dp[s]) < __builtin_popcount(dp[t])) {
		    dp[s] = dp[t];
		}
	    }
	}

	ULL ans = 0;
	EACH (e, right_sets) {
	    ULL s = *e << n/2;
	    ULL a = 0;
	    for (int i=n/2; i<n; i++) if (s>>i&1) a |= adj[i];

	    ULL guess = s | dp[~a & mask];
	    if (__builtin_popcountll(ans) < __builtin_popcountll(guess)) ans = guess;

	}

	return ans;
    } else {
	return -1ULL;
    }
}



int N, M;


char buf[1111];
map<string, int> name;
int in[41];
VI G[41];
LL A[41];

void calc() {

    REP (a, M) if (in[a]) REP (b, M) if (in[b]) if (a != b) {
	A[a] |= 1LL<<b;
    }
    memset(in, 0, sizeof in);
}


void MAIN() {
    scanf("%d%d", &N, &M);
    map<string, int> mp;

    int cur = -1;
    REP (i, N) {
	int d;
	scanf("%d", &d);
	if (d == 1) {
	    cur++;
	    calc();
	} else {
	    scanf("%s", buf);
	    auto it = name.find(buf);
	    if (it == name.end()) {
		it = name.emplace(buf, name.size()).first;
	    }
	    in[it->second] = true;
	    //	    eprintf("%s %d\n", it->first.c_str(), it->second);
	    G[it->second].push_back(cur);
	}
    }

    cur++;
    calc();

//#ifdef LOCAL
//    M = 40;
//    memset(A, 0, sizeof A);
//    REP (i, M-1) {
//	A[i] |= 1LL<<(i+1);
//	A[i+1] |= 1LL<<i;
//    }
//#endif

    ULL s = indipendent_set((ULL*)A, M);

    int ans = __builtin_popcountll(s);

    printf("%d\n", ans);
//    printf("%llu\n", s);
}

int main() {
    int TC = 1;
    //    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}