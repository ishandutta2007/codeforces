#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int N, K;
char S[100011];
int C[26];

void MAIN() {
    scanf("%d%d%s", &N, &K, S);

    if (N % K != 0) {
	puts("-1");
    } else {
	memset(C, 0, sizeof C);
	int len = -1;
	char ch;
	REP (i, N) {
	    for (char c=S[i]+1; c<='z'; c++) {
		C[c-'a']++;
		int rest = N - i - 1;
		REP (k, 26) {
		    int m = C[k] % K;
		    if (m) rest -= K - m;
		}
		C[c-'a']--;

		if (rest >= 0) {
		    len = i;
		    ch = c;
		    break;
		}
	    }
	    C[S[i]-'a']++;
	}

	bool yes = true;
	REP (k, 26) {
	    int m = C[k] % K;
	    if (m) yes = false;
	}

	if (yes) {
	    puts(S);
	} else {
	    memset(C, 0, sizeof C);
	    S[len] = ch;
	    REP (i, len+1) C[S[i]-'a']++;
	    vector<char> H;

	    len++;
	    REP (k, 26) while (C[k] % K) {
		H.push_back(k+'a');
		C[k]++;
	    }
	    while ((int)H.size() + len < N) H.push_back('a');
	    sort(H.begin(), H.end());
	    REP (i, H.size()) S[len++] = H[i];
	    assert(len == N);
	    puts(S);
	}
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}