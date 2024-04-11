#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

int N;
char S[100011];
char T[100011];
vector<pair<char, char> > P;

void MAIN() {
    scanf("%d%s%s", &N, S, T);
    P.clear();
    REP (i, N) {
	char a = S[i], b = T[N-1-i];
	if (a > b) swap(a, b);
	P.emplace_back(a, b);
    }

    sort(P.begin(), P.end());


    bool yes = true;
    int cnt = 0;
    for (int i=0, j=0; i<(int)P.size(); i=j) {
	while (j < (int)P.size() && P[i] == P[j]) j++;
	if ((j-i) % 2) {
	    if (P[i].first != P[i].second) yes = false;
	    cnt++;
	}
    }
    // REP (i, P.size()) eprintf("%c %c\n", P[i].first, P[i].second);

    if (cnt > 1) yes = false;

    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}