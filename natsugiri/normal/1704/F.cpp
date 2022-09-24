#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>

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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}


int F[501];
void init() {
    VI V;
    for (int i=1; i<=500; i++) {
	V.clear();
	REP (j, i) {
	    int left = max(0, j-1);
	    int right = max(0, i-j-2);
	    V.push_back(F[left] ^ F[right]);
	}
	V.push_back(1<<20);
	sort_unique(V);
	REP (j, V.size()) if (V[j] != j) {
	    F[i] = j;
	    break;
	}
	// printf("%d ", F[i]);
    }
//    REP (i, 501) {
//	if (i % 34 == 0) puts("");
//	printf("%2d", F[i]);
//    }
}

int nim(int len) {
    if (len >= 100) {
	len = (len - 100) % 34 + 100;
    }
    return F[len];
}

int N;
char S[500011];
void MAIN() {
    // exit(0);

    scanf("%d%s", &N, S);

    int r = count(S, S+N, 'R');
    int b = N - r;
    bool alice = false;
    if (r > b) alice = true;
    else if (r < b) alice = false;
    else {
	string g;
	REP (i, N-1) {
	    g.push_back('0' + (S[i] != S[i+1]? 1: 0));
	}
	int m = 0;
	for (int i=0; i<(int)g.size(); ) {
	    if (g[i] == '0') {
		i++;
	    } else {
		int j = i;
		while (j < (int)g.size() && g[j] == '1') j++;
		m ^= nim(j-i);
		i = j;
	    }
	}


	alice = (bool)m;
    }
    puts(alice?"Alice":"Bob");
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}